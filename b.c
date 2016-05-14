# include "vm.h"

void bcc() {			/* Not implemented in call table */
	if (!psw.cbit)
		branch();
	a_branch = no_op = TRUE;
}


void bcs() {
	if (psw.cbit)
		branch();
	a_branch = no_op = TRUE;
}


void beq() {
	if (psw.zbit)
		branch();
	a_branch = no_op = TRUE;
}


void bge() {
	if (!(psw.nbit ^ psw.vbit))
		branch();
	a_branch = no_op = TRUE;
}


void bgt() {
	if (!(psw.zbit | (psw.nbit ^ psw.vbit)))
		branch();
	a_branch = no_op = TRUE;
}


void bhi() {
	if (!psw.cbit && !psw.zbit)
		branch();
	a_branch = no_op = TRUE;
}


void bhis() {
	if (!psw.cbit)
		branch();
	a_branch = no_op = TRUE;
}


void bic() {
	int	*op1, *op2;

	two_op = TRUE;
	get_source_dest(&op1, &op2);
	answer = *op2 = ~*op1 & *op2;
	psw.nbit = (answer < 0 ? 1 : 0);
	psw.zbit = (answer == 0 ? 1 : 0);
	psw.vbit = 0;
}


void bicb() {
	int	*op1, *op2;
	char	*byte_1, *byte_2;

	two_op = byte_op = TRUE;
	get_source_dest(&op1, &op2);
	byte_1 = (char *)op1;
	byte_2 = (char *)op2;
	if (usehi_1)
		++byte_1;
	if (usehi_2)
		++byte_2;
	*byte_2 = ~*byte_1 & *byte_2;
	answer = *byte_2;
	psw.nbit = (answer < 0 ? 1 : 0);
	psw.zbit = (answer == 0 ? 1 : 0);
	psw.vbit = 0;
}


void bis() {
	int	*op1, *op2;

	two_op = TRUE;
	get_source_dest(&op1, &op2);
	answer = *op2 = *op1 | *op2;
	psw.nbit = (answer < 0 ? 1 : 0);
	psw.zbit = (answer == 0 ? 1 : 0);
	psw.vbit = 0;
}


void bisb() {
	int	*op1, *op2;
	char	*byte_1, *byte_2;

	two_op = byte_op = TRUE;
	get_source_dest(&op1, &op2);
	byte_1 = (char *)op1;
	byte_2 = (char *)op2;
	if (usehi_1)
		++byte_1;
	if (usehi_2)
		++byte_2;
	*byte_2 = *byte_1 | *byte_2;
	answer = *byte_2;
	psw.nbit = (answer < 0 ? 1 : 0);
	psw.zbit = (answer == 0 ? 1 : 0);
	psw.vbit = 0;
}


void ble() {
	if ((psw.zbit | (psw.nbit ^ psw.vbit)))
		branch();
	a_branch = no_op = TRUE;
}


void blo() {
	if (psw.cbit)
		branch();
	a_branch = no_op = TRUE;
}


void blos() {
	if (psw.cbit || psw.zbit)
		branch();
	a_branch = no_op = TRUE;
}


void blt() {
	if ((psw.nbit ^ psw.vbit))
		branch();
	a_branch = no_op = TRUE;
}


void bmi() {
	if (psw.nbit)
		branch();
	a_branch = no_op = TRUE;
}


void bne() {
	if (!psw.zbit)
		branch();
	a_branch = no_op = TRUE;
}


void bpl() {
	if (!psw.nbit)
		branch();
	a_branch = no_op = TRUE;
}


void br() {
	branch();
	a_branch = no_op = TRUE;
}


void bvc() {
	if (!psw.vbit)
		branch();
	a_branch = no_op = TRUE;
}


void bvs() {
	if (psw.vbit)
		branch();
	a_branch = no_op = TRUE;
}
