/*****************************************************************************/
/*                 G E N E R A T E D       C    C O D E                      */
/*****************************************************************************/
/* KIELER - Kiel Integrated Environment for Layout Eclipse RichClient        */
/*                                                                           */
/* http://www.informatik.uni-kiel.de/rtsys/kieler/                           */
/* Copyright 2014 by                                                         */
/* + Kiel University                                                         */
/*   + Department of Computer Science                                        */
/*     + Real-Time and Embedded Systems Group                                */
/*                                                                           */
/* This code is provided under the terms of the Eclipse Public License (EPL).*/
/*****************************************************************************/
char opening_timer_ex;
char generateClosing_state;
char door_closed;
char door_open;
char waitUser_ex;
char door_touched;
char waitUser_state;
char init_state;
char waitTouch_state;
char generateOpening_state;
char g0;
char g1;
char PRE_g1;
char g2;
char g2b;
char g3;
char PRE_g3;
char g4;
char g5;
char g6;
char PRE_g6;
char g7;
char g8;
char g9;
char PRE_g9;
char g10;
char g11;
char g12;
char PRE_g12;
char g13;
char g14;
char g15;
char PRE_g15;
char g16;
char g17;
char g18;
char g19;
char g20;
char g21;
char g22;
char g23;
char g24;
char PRE_g24;
char g25;
char g26;
char g27;
char _GO;
char _cg20;
char _cg4;
char _cg7;
char _cg18;
char _cg10;
char _cg13;
char _cg16;
char g22_e1;
char g26_e2;
int _PRE_GO;
void reset(){
	_GO = 1;
	_PRE_GO = 0;
	PRE_g1 = 0;
	PRE_g3 = 0;
	PRE_g6 = 0;
	PRE_g9 = 0;
	PRE_g12 = 0;
	PRE_g15 = 0;
	PRE_g24 = 0;
	return;
}
void tick(){
	if(_PRE_GO == 1){
		_GO = 0;
	}
	{
		g0 = _GO;
		g1 = g0;
		g2 =(PRE_g1);
		g25 =(PRE_g24);
		g23 = g0;
		g24 =(g25||g23);
		if(g24){
			waitUser_state = 0;
			init_state = 0;
			waitTouch_state = 0;
			generateOpening_state = 0;
			generateClosing_state = 0;
		}
		g2b = g2;
		if(g2b){
			init_state =(init_state||1);
		}
		g4 =(PRE_g3);
		_cg4 = door_closed;
		g20 =(g4&&(!(_cg4)));
		_cg20 = door_open;
		g3 =((g20&&(!(_cg20)))||g2b);
		g5 =(g4&&_cg4);
		if(g5){
			waitTouch_state =(waitTouch_state||1);
		}
		g16 =(PRE_g15);
		_cg16 = door_closed;
		g17 =(g16&&_cg16);
		if(g17){
			waitTouch_state =(waitTouch_state||1);
		}
		g7 =(PRE_g6);
		_cg7 = door_touched;
		g10 =(PRE_g9);
		_cg10 = door_open;
		g18 =(g10&&(!(_cg10)));
		_cg18 = opening_timer_ex;
		g19 =(g18&&_cg18);
		if(g19){
			waitTouch_state =(waitTouch_state||1);
		}
		g6 =(g17||g5||(g7&&(!(_cg7)))||g19);
		g8 =(g7&&_cg7);
		if(g8){
			generateOpening_state =(generateOpening_state||1);
		}
		g9 =(g8||(g18&&(!(_cg18))));
		g11 =(g10&&_cg10);
		if(g11){
			waitUser_state =(waitUser_state||1);
		}
		g13 =(PRE_g12);
		_cg13 = waitUser_ex;
		g21 =(g20&&_cg20);
		if(g21){
			waitUser_state =(waitUser_state||1);
		}
		g12 =(g11||(g13&&(!(_cg13)))||g21);
		g14 =(g13&&_cg13);
		if(g14){
			generateClosing_state =(generateClosing_state||1);
		}
		g15 =((g16&&(!(_cg16)))||g14);
		g22_e1 =(!((g2||g4||g7||g13||g10||g16)));
		g26_e2 =(!(g25));
	}
	PRE_g1 = g1;
	PRE_g3 = g3;
	PRE_g6 = g6;
	PRE_g9 = g9;
	PRE_g12 = g12;
	PRE_g15 = g15;
	PRE_g24 = g24;
	_PRE_GO = _GO;
	return;
}
