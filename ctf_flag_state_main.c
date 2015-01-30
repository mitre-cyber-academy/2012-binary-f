/*
	user provides characters via command line input like so:
	> ctf_puzzle MCA-1234567 
	those characters are parsed in order and determine the state, 
	if the states transition in the proper order, they receive a 
	positive message to know they've done it.
	otherwise negative feedback suggests they need to try again.

	this essentially forces them to step through this using a debugger 
	to determine the proper order.  Technically they never have to 
	execute the program to solve this.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctf_flag_states.h"
		

FSM *FSM_Ctor(unsigned int arg_len, char init_state) {

  FSM *fsm = (FSM *)malloc(sizeof(FSM));
	if (!fsm)
		return NULL;	

	if (arg_len != 12) {
		printf("\nEnter the flag as cmd-line input (12 numbers/letters/(+1 dash), letters in CAPS) ;)\n");
		FSM_Dtor(fsm);
		return NULL;
	}

	fsm->state = Get_State(init_state);
	fsm->prevState = Initial;	// no love for this
	fsm->arg_len = arg_len;
	fsm->arg_index = 0;
	fsm->score = 0;

  return fsm;
}

void FSM_Dtor(FSM *fsm) {
	free(fsm);
}

int main(unsigned int argc, char *argv[]) {
	sleep(1);
	FSM *fsm;
	unsigned long long start_ticks, end_ticks, tick_count;

	if (argc != 2) {
		printf(" Use a single command-line argument (12 numbers/letters/(+1 dash), letters in CAPS)\n\n");
		goto The_End;	
	}
	
	// the command line input length is tracked and the first letter determine the initial state
	fsm = FSM_Ctor(strlen(argv[1]), argv[1][0]);
	if (!fsm)
		goto The_End;	
	
	// The engine that drives this
  while(1) {
		start_ticks = Read_Timer();		
		// the actual engine that drives this
    (fsm->state)(fsm, argv[1][fsm->arg_index+1]);	// execution time is roughly measured
		end_ticks = Read_Timer();
		tick_count = end_ticks - start_ticks;
		if (tick_count > 0x800000)
			fsm->state = Fail;
		fsm->arg_index++;
  }

The_End:
	return 0;
}
