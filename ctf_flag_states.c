#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctf_flag_states.h"

/* Flag = MCA-173E6D84 */

// reads the timer output of rdtsc instruction
unsigned long long Read_Timer() {
	unsigned int cycles_high = 0;
	unsigned int cycles_low = 0;
	unsigned long long cycles_total = 0;

#ifdef _WIN32
	__asm {
		cpuid;	// serialize
		rdtsc;
		mov cycles_high, edx;
		mov cycles_low, eax;
	};
#elif defined __linux__
	asm("cpuid");	// serialize
	asm("rdtsc");
	asm("mov %%edx, %0" : "=a"(cycles_high));
	asm("mov %%eax, %0" : "=a"(cycles_low));
#endif

	return (((cycles_total | cycles_high) << 32) | cycles_low);
}

void Success(FSM *fsm, char nextState) {
	if (fsm->arg_index == 12 && fsm->score == 0xb) {	// hack of a bugfix
		printf(" Soft eyes, grasshopper.  Now carry that flag onward to victory!\n\n");
		FSM_Dtor(fsm);
		exit(0);		// nothing like a graceful exit
	}
	else 
		fsm->state = Fail;
}

void Fail(FSM *fsm, char nextState) {
	printf(" Nope.\n \"If you got soft eyes, you can see the whole thing. If you got hard eyes - you staring at the same tree missing the forest.\" -- 'Bunk' Moreland\n\n");
	FSM_Dtor(fsm);
	exit(0);		// yeah
}

void Dash(FSM *fsm, char nextState) {
	if (fsm->prevState == A) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

// modified this so we never come here.  the first letter of cmdline input 
// determines the state, as it should always have done
void Initial(FSM *fsm, char nextState) {
	if (nextState == 'M') {
		fsm->state = M;
		fsm->prevState = Initial;	// hasn't actually changed yet but ...
	}
	else 
		fsm->state = Fail;
}

void A(FSM *fsm, char nextState) {
	if (fsm->prevState == C) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;		
	}
	else 
		fsm->state = Fail; 
}

void B(FSM *fsm, char nextState) {
	if (fsm->prevState == X) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void C(FSM *fsm, char nextState) {
	if (fsm->prevState == M) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

void D(FSM *fsm, char nextState) {
	if (fsm->prevState == Six) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

void E(FSM *fsm, char nextState) {
	if (fsm->prevState == Three) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

void F(FSM *fsm, char nextState) {
	if (fsm->prevState == Seven) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void G(FSM *fsm, char nextState) {
	if (fsm->prevState == H) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void H(FSM *fsm, char nextState) {
	if (fsm->prevState == Z) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void I(FSM *fsm, char nextState) {
	if (fsm->prevState == Four) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void J(FSM *fsm, char nextState) {
	if (fsm->prevState == G) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void K(FSM *fsm, char nextState) {
	if (fsm->prevState == Y) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void L(FSM *fsm, char nextState) {
	if (fsm->prevState == One) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

// the actual flag "states", each one is basically identical
void M(FSM *fsm, char nextState) {
	if (fsm->prevState == Initial) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail;
}

void N(FSM *fsm, char nextState) {
	if (fsm->prevState == Two) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void O(FSM *fsm, char nextState) {
	if (fsm->prevState == L) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void P(FSM *fsm, char nextState) {
	if (fsm->prevState == Dash) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void Q(FSM *fsm, char nextState) {
	if (fsm->prevState == K) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void R(FSM *fsm, char nextState) {
	if (fsm->prevState == Five) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void S(FSM *fsm, char nextState) {
	if (fsm->prevState == P) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void T(FSM *fsm, char nextState) {
	if (fsm->prevState == Six) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void U(FSM *fsm, char nextState) {
	if (fsm->prevState == V) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void V(FSM *fsm, char nextState) {
	if (fsm->prevState == W) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void W(FSM *fsm, char nextState) {
	if (fsm->prevState == X) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void X(FSM *fsm, char nextState) {
	if (fsm->prevState == Z) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void Y(FSM *fsm, char nextState) {
	if (fsm->prevState == X) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void Z(FSM *fsm, char nextState) {
	if (fsm->prevState == One) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
	}
	else 
		fsm->state = Fail; 
}

void One(FSM *fsm, char nextState) {
	if (fsm->prevState == Dash) {
		fsm->state = Get_State(nextState);
		fsm->prevState = One;
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

// unused state
void Two(FSM *fsm, char nextState) {
	if (fsm->prevState == Z) {
		fsm->state = Get_State(nextState);
		fsm->prevState = One;
	}
	else 
		fsm->state = Fail; 
}

void Three(FSM *fsm, char nextState) {
	if (fsm->prevState == Seven) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

// last state - if you transition to here you win
void Four(FSM *fsm, char nextState) {
	if (fsm->prevState == Eight) {
		fsm->prevState = fsm->state;
		fsm->state = Success;
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

// unused state
void Five(FSM *fsm, char nextState) {
	if (fsm->prevState == One) {
		fsm->state = Get_State(nextState);
		fsm->prevState = One;
	}
	else 
		fsm->state = Fail; 
}

void Six(FSM *fsm, char nextState) {
	if (fsm->prevState == E) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

void Seven(FSM *fsm, char nextState) {
	if (fsm->prevState == One) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

void Eight(FSM *fsm, char nextState) {
	if (fsm->prevState == D) {
		fsm->prevState = fsm->state;
		fsm->state = Get_State(nextState);
		fsm->score++;
	}
	else 
		fsm->state = Fail; 
}

// unused state
void Nine(FSM *fsm, char nextState) {
	if (fsm->prevState == Two) {
		fsm->state = Get_State(nextState);
		fsm->prevState = One;
	}
	else 
		fsm->state = Fail; 
}

// unused state
void Zero(FSM *fsm, char nextState) {
	if (fsm->prevState == A) {
		fsm->state = Get_State(nextState);
		fsm->prevState = One;
	}
	else 
		fsm->state = Fail; 
}

// helper function to convert command line input into a state
// can change the order of these since it gives away the first few chars of flag
// a lookup table would look nicer
State Get_State(const char c) {
	switch(toupper(c)) {
	case '-':
		return Dash;
		break;
	case '1':
		return One;
		break;
	case '2':
		return Two;
		break;
	case '3':
		return Three;
		break;
	case '4':
		return Four;
		break;
	case '5':
		return Five;
		break;
	case '6':
		return Six;
		break;
	case '7':
		return Seven;
		break;
	case '8':
		return Eight;
		break;
	case '9':
		return Nine;
		break;
	case '0':
		return Zero;
		break;
	case 'A':
		return A;
		break;
	case 'B':
		return B;
		break;
	case 'C':
		return C;
		break;
	case 'D':
		return D;
		break;
	case 'E':
		return E;
		break;
	case 'F':
		return F;
		break;
	case 'G':
		return G;
		break;
	case 'H':
		return H;
		break;
	case 'I':
		return I;
		break;
	case 'J':
		return J;
		break;
	case 'K':
		return K;
		break;
	case 'L':
		return L;
		break;
	case 'M':
		return M;
		break;
	case 'N':
		return N;
		break;
	case 'O':
		return O;
		break;
	case 'P':
		return P;
		break;
	case 'Q':
		return Q;
		break;
	case 'R':
		return R;
		break;
	case 'S':
		return S;
		break;
	case 'T':
		return T;
		break;
	case 'U':
		return U;
		break;
	case 'V':
		return V;
		break;
	case 'W':
		return W;
		break;
	case 'X':
		return X;
		break;
	case 'Y':
		return Y;
		break;
	case 'Z':
		return Z;
		break;
	default:
		return Fail;
	}
}

// randomize a Fail state transition to break up the monotony 
// unused.  would make it too difficult IMO
/*unsigned char Get_Rand_Char() {
	unsigned char RandChar[36] = {'0','1','2','3','4','5','6','7','8','9','A','B',\
																'C','D','E','F','G','H','I','J','K','L','M','N',\
																'O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	unsigned int random32;
	__asm {
		push edx;
		call get_rand32;
		mov edx, 0x24;	// = 36d = length of RandChar array
		mul edx;
		mov random32, edx;
		pop edx;
		jmp End;

get_rand32:
		push edx;
		rdtsc;
		mov edx, 0x0019660D;
		mul edx;
		add eax, 0x3C6EF35F;
		pop edx;
		ret;
End:
	};
	//unsigned char blah = RandChar[random32];	// dbg
	return RandChar[random32];
}*/
