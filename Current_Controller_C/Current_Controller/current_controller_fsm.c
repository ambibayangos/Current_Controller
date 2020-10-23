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
char doorAlmostClosed;
char startWaitUserTimer;
char doorOpen;
char doorClosed;
char touched;
char waitUser_ex;
char openingTimer_ex;
char init_state;
char waitTouch_state;
char generateOpening_state;
char waitUser_state;
char breaking_state;
char generareClosing_state;
char startOpeningTimer;
char startSoftCloseTimer;
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
char g17b;
char g18;
char PRE_g18;
char g19;
char g20;
char g20b;
char g21;
char g22;
char g23;
char g24;
char g25;
char g26;
char g27;
char g28;
char g29;
char g30;
char g31;
char g32;
char g33;
char PRE_g33;
char g34;
char g35;
char g36;
char _GO;
char _cg4;
char _cg7;
char _cg10;
char _cg13;
char _cg16;
char _cg19;
char _cg21;
char _cg28;
char g31_e1;
char g35_e2;
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
	PRE_g18 = 0;
	PRE_g33 = 0;
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
		g32 = g0;
		g34 =(PRE_g33);
		g33 =(g32||g34);
		if(g33){
			init_state = 0;
			waitTouch_state = 0;
			generateOpening_state = 0;
			waitUser_state = 0;
			breaking_state = 0;
			generareClosing_state = 0;
			startOpeningTimer = 0;
			startSoftCloseTimer = 0;
			startWaitUserTimer = 0;
		}
		g2b = g2;
		if(g2b){
			init_state =(init_state||1);
		}
		g4 =(PRE_g3);
		_cg4 = doorOpen;
		g28 =(g4&&(!(_cg4)));
		_cg28 = doorClosed;
		g30 =(g28&&(!(_cg28)));
		if(g30){
			init_state =(init_state||1);
		}
		g3 =(g2b||g30);
		g5 =(g4&&_cg4);
		if(g5){
			waitUser_state =(waitUser_state||1);
		}
		g19 =(PRE_g18);
		_cg19 = doorOpen;
		g20 =(g19&&_cg19);
		if(g20){
			startWaitUserTimer =(startWaitUserTimer||1);
		}
		g20b = g20;
		if(g20b){
			waitUser_state =(waitUser_state||1);
		}
		g7 =(PRE_g6);
		_cg7 = waitUser_ex;
		g27 =(g7&&(!(_cg7)));
		if(g27){
			waitUser_state =(waitUser_state||1);
		}
		g6 =(g5||g20b||g27);
		g8 =(g7&&_cg7);
		if(g8){
			breaking_state =(breaking_state||1);
		}
		g10 =(PRE_g9);
		_cg10 = doorAlmostClosed;
		g26 =(g10&&(!(_cg10)));
		if(g26){
			breaking_state =(breaking_state||1);
		}
		g9 =(g8||g26);
		g11 =(g10&&_cg10);
		if(g11){
			generareClosing_state =(generareClosing_state||1);
		}
		g13 =(PRE_g12);
		_cg13 = doorClosed;
		g25 =(g13&&(!(_cg13)));
		if(g25){
			generareClosing_state =(generareClosing_state||1);
		}
		g12 =(g25||g11);
		g14 =(g13&&_cg13);
		if(g14){
			waitTouch_state =(waitTouch_state||1);
		}
		g16 =(PRE_g15);
		_cg16 = touched;
		g24 =(g16&&(!(_cg16)));
		if(g24){
			waitTouch_state =(waitTouch_state||1);
		}
		g29 =(g28&&_cg28);
		if(g29){
			waitTouch_state =(waitTouch_state||1);
		}
		g21 =(g19&&(!(_cg19)));
		_cg21 = openingTimer_ex;
		g22 =(g21&&_cg21);
		if(g22){
			waitTouch_state =(waitTouch_state||1);
		}
		g15 =(g24||g14||g29||g22);
		g17 =(g16&&_cg16);
		if(g17){
			startOpeningTimer =(startOpeningTimer||1);
		}
		g17b = g17;
		if(g17b){
			generateOpening_state =(generateOpening_state||1);
		}
		g23 =(g21&&(!(_cg21)));
		if(g23){
			generateOpening_state =(generateOpening_state||1);
		}
		g18 =(g17b||g23);
		g31_e1 =(!((g2||g4||g7||g16||g10||g19||g13)));
		g35_e2 =(!(g34));
	}
	PRE_g1 = g1;
	PRE_g3 = g3;
	PRE_g6 = g6;
	PRE_g9 = g9;
	PRE_g12 = g12;
	PRE_g15 = g15;
	PRE_g18 = g18;
	PRE_g33 = g33;
	_PRE_GO = _GO;
	return;
}
