Finite State Machine Puzzle

AUTHOR: John Butterworth

	User provides characters via command line input like so:
	> ctf_puzzle MCA-1234567 
	
	Those characters are parsed in order and will comprise
	the flag you are trying to determine.  It is your job to figure 
	out the correct input and therefore the flag by RE'ing/debugging  
	the binary.
	
	When you see the positive message you know you have entered the
	correct flag.  Like all other flags, this one is 12 characters long
	and you know it begins with MCA-.  Letters do not have to be in CAPS
	for this.
	
	Choose either the Linux or Windows binaries, depending on your preference.  
	Both are identical in their control-flow and solution.  Both are compiled 
	for 32-bit and have been tested to work on 64-bit OS platforms (64-bit 
	Ubuntu and Win7x64).	If on linux, there is an included gdb commands file 
	to maybe assist you in this arduous task: (gdb ctf_fsm_puzzle_linux -x gdbCmds).  
	Good Luck!
	
flag is MCA-173E6D84
