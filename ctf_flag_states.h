#ifndef _CTF_PUZZLE_H_
#define _CTF_PUZZLE_H_

typedef struct Finite_State_Machine FSM;
typedef void (*State)(FSM *fsm, char nextState);

struct Finite_State_Machine {
	State state;
	State prevState;
	unsigned int arg_len;
	unsigned int arg_index;
	unsigned int score;			// provides a clue in some otherwise really obfuscated code
};

// each character in the flag represents a different state
void Initial(FSM *, char);	// initial state
void Fail(FSM *, char);	// failure/exit state
void Success(FSM *, char);
void A(FSM *, char);
void B(FSM *, char);
void C(FSM *, char);
void D(FSM *, char);
void E(FSM *, char);
void F(FSM *, char);
void G(FSM *, char);
void H(FSM *, char);
void I(FSM *, char);
void J(FSM *, char);
void K(FSM *, char);
void L(FSM *, char);
void M(FSM *, char);
void N(FSM *, char);
void O(FSM *, char);
void P(FSM *, char);
void Q(FSM *, char);
void R(FSM *, char);
void S(FSM *, char);
void T(FSM *, char);
void U(FSM *, char);
void V(FSM *, char);
void W(FSM *, char);
void X(FSM *, char);
void Y(FSM *, char);
void Z(FSM *, char);
void Zero(FSM *, char);	
void One(FSM *, char);
void Two(FSM *, char);
void Three(FSM *, char);
void Four(FSM *, char);
void Five(FSM *, char);
void Six(FSM *, char);
void Seven(FSM *, char);
void Eight(FSM *, char);
void Nine(FSM *, char);
void Dash(FSM *, char);

// couple declarations
FSM *FSM_Ctor(unsigned int, char);
void FSM_Dtor(FSM *);
State Get_State(const char);
unsigned long long Read_Timer();
unsigned char Get_Rand_Char();

#endif
