#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// 3 different types of structs to provide for 3 different linked lists, input, output, temp
typedef struct inputNode{
	char var[30];
	struct inputNode *next;
	int data;
}inNode;

typedef struct outputNode{
	char var[30];
	struct outputNode *next;
	// pos = data //
	int data;
	int num;
}outNode;

typedef struct temporaryNode{
	char var[30];
	struct temporaryNode *next;
	int data;
	int num;
}tempNode;
	inNode *headIn = NULL;
	inNode *tempIn = NULL;
	outNode *headOut = NULL;
	outNode *tempOut = NULL;
	tempNode *passIn = NULL;
	tempNode *passCur = NULL;
// put the nodes inputted into a linked list //
void insertIn(int n, char *ptr){
	inNode *current;
	current = (inNode*)malloc(sizeof(inNode));
(*current).data = n;
strcpy(current->var, ptr); 
current->next = NULL;
if(headIn == NULL){
	headIn = current;
	tempIn = current;
	return;
	}
tempIn->next = current;
tempIn = tempIn->next;
}
// put the nodes outputted into a linked list //
void insertOut(int n, char *ptr){
	outNode *current;
	current = (outNode*)malloc(sizeof(outNode));
(*current).data = n;
strcpy(current->var, ptr);
current->next = NULL;
if(headOut == NULL){
	headOut = current;
	tempOut = current;
	return;
	}
tempOut->next = current;
tempOut = tempOut->next;
}
// insert value on the outnode list
void insertNum(int number, char *ptr, outNode *first){
outNode *current = first;
while(current!= NULL){
	if(strcmp(current->var, ptr) == 0)
		current->num = number;
		current = current->next;
}
}
void insertPass(int n, char *ptr){
	tempNode *current;
	current = (tempNode*)malloc(sizeof(tempNode));
	current->data = n;
	strcpy(current->var, ptr); 
	current->next = NULL;
	if(passIn == NULL){
		passIn = current;
		passCur = current;
		return;
}
passCur->next = current;
passCur = passCur->next;
}

void printNode(inNode *first){
	while(first != NULL){
		printf("%d %s\n", (*first).data, (*first).var);
		first = first->next;
	}
} 
void printNodeOut(outNode *first){
	while(first != NULL){
		printf("%d %s\n", (*first).num, (*first).var);
		first = first->next;
	}
}
// find the value in the node by doing a character array comparison
int getNum(char *ptr, inNode *head){
inNode *current = head;

while(current != NULL){
	if(strcmp(current->var,ptr)==0)
	return (current->data);
	current = current->next;
}
return -1;
}


int getTempNum(char *ptr, tempNode *head){
tempNode *current = head;

while(current != NULL){
	if(strcmp(current->var,ptr) == 0)
	return (current->data);
	current = current->next;
}
return -1;
}


int getOutNum(char *ptr, outNode *head){
outNode *current = head;

while(current != NULL){
	if(strcmp(current->var,ptr) == 0)
	return (current->data);
	current = current->next;
}
return -1;
}



// starting gates
int NOT(int i){
if ( i == 1 )
	return 0;
else if( i == 0 )
	return 1;
	return 0;
}

int AND(int i1, int i2){
if( i1 == 0 && i2 == 0 )
	return 0;
else if ( (i1 == 0 && i2 == 1) || (i1 == 1 && i2 == 0))
	return 0;
else if ((i1 ==1) && (i2 == 1))
	return 1;
 
return 0;
}

int OR(int i1, int i2){
if( i1 == 0 && i2 == 0)
	return 0;
else if ( (i1 == 0 || i2 == 1) || (i1 == 1 || i2 == 0))
	return 1;
else if ( i1 == 1 && i2 == 1)
	return 1;

return 0;
}

int XOR(int i1, int i2){

if( i1 == 0 && i2 == 0)
	return 0;
else if ( i1 == 1 && i2 == 1)
	return 0;
else if ( (i1 == 0 || i2 == 1) || (i1 == 1 || i2 == 0))
	return 1;

return 0;
}
int NAND(int i1, int i2){
if( i1 == 0 && i2 == 0 )
	return 1;
else if ( (i1 == 0 && i2 == 1) || (i1 == 1 && i2 == 0))
	return 1;
else if (i1 == 1 && i2 == 1)
	return 0;
 
return 0;
}

int NOR(int i1, int i2){
if( i1 == 0 && i2 == 0)
	return 1;
else if ( (i1 == 0 || i2 == 1) || (i1 == 1 || i2 == 0))
	return 0;
return 0;
}
int PASS(int i){
return i;
}

void maketruthtable(int row, int col, int** arr){
	int a,b = 0;
	int value = 0;
	int count = 0;
	int reset = 0; 
// value = 3 test;
for ( a = 0; a < col; a++){
value = (row / (pow(2, a+1)));
reset = value;
count = 0;
	for ( b = 0; b < row; b++){
	if(count == reset){
	value = reset;
	count = 0;
	}		
	value = value - 1;
	if(value < 0){
	arr[b][a] = 1;
	count++;
	}
	else{
	arr[b][a] = 0;
	}

}
}
}
void printTable(int row, int col, int** arr){
int x = 0;
int y = 0;
for ( x = 0; x < row; x++){
	for ( y = 0; y < col; y++){
		printf("%d ", arr[x][y]);
	}
	printf("| ");
	printf("\n");
}
}

void printAnswer(int row, int col, int** arr, outNode *head, int n){
// if this is printed 8 times, then we need to print out each array 
outNode *current = head;
int y = 0;

	for ( y = 0; y < col; y++){
		printf("%d ", arr[n][y]);
	}
	printf("|");
	while ( current != NULL){
	printf("% d", (current->num));
	current = current->next;
	}
	printf("\n");

}
int main(int argc, char *argv[]){
// char arrays have null terminating character at the end //
	char input[6];
	char output[7];
	int numIn = 0;
	int numOut = 0;
	int i = 0;
	char varIn[30];
	char varOut[30];
	char instruct[30];
	char gets[100];
	fpos_t pos;
	int bit = 1;
	int count = 0;
	
	       		
// Use linked list to keep count of the unknown # of inputs //
// Open the file, only 1 text argument //
FILE *fp = fopen(argv[1], "r");
if(fp == 0){
	printf("%s", "error");
	exit(0);
}

// first two lines of text file has to be INPUT then OUTPUT //


fscanf(fp, "%5c %d", input, &numIn);
if(input[0] != 'I' || input[1] != 'N' || input[2] != 'P' || input[3] != 'U' || input[4] != 'T')
	exit(0);
if(!(numIn > 0))
	exit(0);

for( i = 1; i <= numIn; i++){
	fscanf(fp, "%s", varIn);
	if(strcmp(varIn, ":") == 0){
	varIn[0] = 0;
	fscanf(fp, "%s", varIn);
	}
	insertIn(i, varIn);
		
}
//printf("%s\n", input);
//printNode(headIn);
// fscanf behaves weirdly, must read in the newline character in order to go to next line successfully //
fscanf(fp, "\n");
fscanf(fp, "%6c %d", output, &numOut);
if(output[0] != 'O' || output[1] != 'U' || output[2] != 'T' || output[3] != 'P' || output[4] != 'U' || output[5] != 'T')
	exit(0);
if(!(numOut >0))
	exit(0);
for(i = 1; i <= numOut; i++){
	fscanf(fp, "%s", varOut);
	if(strcmp(varOut, ":")== 0){
	varOut[0] = 0;
	fscanf(fp, "%s", varOut);
	}
	insertOut(i, varOut);
	

}
output[6] = '\0';
//printf("%s", output);
//printNodeOut(headOut);

fgetpos(fp, &pos);
//get possible outputs //
for ( i = 0; i < numIn; i++){
bit *= 2;
}

int** truthtable = (int**)malloc(bit *sizeof(int*));
for( i = 0; i < bit; i++){
	truthtable[i] = malloc(numIn*sizeof(int));
}
maketruthtable(bit, numIn, truthtable);
//printTable(bit, numIn, truthtable);

// bit = row, numIn = col//
// make a method to retrieve a number from instruction//
int a = 0;
int in = 0;
 int b = 0;
int out = 0;
int temp = 1;
int temp2 = 1;
char varTemp[30];
char varTemp2[30];
char varO[30];
int tabAnswer = 0;
int it = 0;


for(i = 1; i <= bit; i++){

/* only two options: one is input, or one is temp. therefore, scan 2 integers for input or temp linked list.
 scan the 3rd string. either output or temp*/
while(fgets(gets,100,fp) != NULL){
fscanf(fp, "%s", instruct);
if(strcmp(instruct, "NOT") == 0)
{

	fscanf(fp, "%s", varTemp);
	in = getNum(varTemp, headIn);
	
	fscanf(fp, "%s", varO);
	if(strcmp(varO, ":")== 0){
	varO[0] = 0;
	fscanf(fp, "%s", varO);
	}
	
	out = getOutNum(varO, headOut);

if ( (in == -1) && (out == -1)){ // temp --> temp 
	temp = getTempNum(varTemp, passIn);
	insertPass(temp, varO);
} 
else if( (in != -1) && (out != -1)){ // real --> real
	tabAnswer = (NOT(truthtable[i-1][in-1]));
	insertNum(tabAnswer, varO, headOut);
}
else if((in == -1) && (out != -1)){ // temp --> real
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (NOT(temp));
	insertNum(tabAnswer, varO, headOut);
}
else if ((in != -1) && (out == -1)){ // real --> temp
	tabAnswer = (NOT(truthtable[i-1][in-1]));
	insertPass(tabAnswer, varO);
}
// if out link position not located // 

// if it is located set the output = to the input..
}
else if(strcmp(instruct, "AND") == 0)
{
	fscanf(fp, "%s %s", varTemp, varTemp2);
	fscanf(fp, "%s", varO);
	if(strcmp(varO, ":")== 0){
	varO[0] = 0;
	fscanf(fp, "%s", varO);
	}
	a = getNum(varTemp, headIn);
	b = getNum(varTemp2, headIn);
	out = getOutNum(varO, headOut); // varO is the output string
if( (a == -1) && (b == -1) && (out == -1)){ // temp temp --> temp
	temp = getTempNum(varTemp,passIn);
	temp2 = getTempNum(varTemp2,passIn);
	tabAnswer = (AND(temp, temp2));
	insertPass(tabAnswer, varO);
}
else if( (a != -1) && (b != -1) && (out != -1)){ // real real --> real
	tabAnswer = (AND(truthtable[i-1][a-1], truthtable[i-1][b-1]));

	insertNum(tabAnswer, varO, headOut);
}
else if( (a != - 1) && (b== -1) && (out != -1)){     // real temp --> real
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (AND(truthtable[i-1][a-1], temp2));

	insertNum(tabAnswer, varO, headOut);
}
else if( (a == -1) && (b!= -1) && (out != -1)){ // temp real --> real
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (AND(temp, truthtable[i-1][b-1]));

	insertNum(tabAnswer, varO, headOut);
}
else if ( (a== -1) && (b == -1) && (out != -1)){ // temp temp --> real
	temp = getTempNum(varTemp, passIn);
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (AND(temp, temp2));

	insertNum(tabAnswer, varO, headOut);
}
else if ( (a!= -1) && (b != -1) && (out == -1)){ // real real --> temp
	tabAnswer = (AND(truthtable[i-1][a-1], truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);}
else if ( (a != -1) && (b == -1) && (out == -1)){ // real temp --> temp
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (AND(truthtable[i-1][a-1], temp2));
	insertPass(tabAnswer, varO); 
}
else if ( (a == -1) && (b != -1) && (out == -1)){ // temp real --> temp
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (AND(temp, truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);
}
}
else if(strcmp(instruct, "OR") == 0)
{	
	fscanf(fp, "%s %s", varTemp, varTemp2);
	fscanf(fp, "%s", varO);
	if(strcmp(varO, ":")== 0){
	varO[0] = 0;
	fscanf(fp, "%s", varO);
	}
	a = getNum(varTemp, headIn);
	b = getNum(varTemp2, headIn);
	out = getOutNum(varO, headOut);
if( (a == -1) && (b == -1) && (out == -1)){ // temp temp --> temp
	temp = getTempNum(varTemp,passIn);
	temp2 = getTempNum(varTemp2,passIn);
	tabAnswer = (OR(temp, temp2));
	insertPass(tabAnswer, varO);
}
else if( (a != -1) && (b != -1) && (out != -1)){ // real real --> real
	tabAnswer = (OR(truthtable[i-1][a-1], truthtable[i-1][b-1]));
	insertNum(tabAnswer, varO, headOut);
}
else if( (a != - 1) && (b== -1) && (out != -1)){     // real temp --> real
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (OR(truthtable[i-1][a-1], temp2));
	insertNum(tabAnswer, varO, headOut);
}
else if( (a == -1) && (b!= -1) && (out != -1)){ // temp real --> real
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (OR(temp, truthtable[i-1][b-1]));
	insertNum(tabAnswer, varO, headOut);
}
else if ( (a== -1) && (b == -1) && (out != -1)){ // temp temp --> real
	temp = getTempNum(varTemp, passIn);
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (OR(temp, temp2));
	insertNum(tabAnswer, varO, headOut);
}
else if ( (a!= -1) && (b != -1) && (out == -1)){ // real real --> temp
	tabAnswer = (OR(truthtable[i-1][a-1], truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);}
else if ( (a != -1) && (b == -1) && (out == -1)){ // real temp --> temp
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (OR(truthtable[i-1][a-1], temp2));
	insertPass(tabAnswer, varO); 
}
else if ( (a == -1) && (b != -1) && (out == -1)){ // temp real --> temp
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (OR(temp, truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);
}
}
else if(strcmp(instruct, "NAND") == 0){
	fscanf(fp, "%s %s", varTemp, varTemp2);
	fscanf(fp, "%s", varO);
	if(strcmp(varO, ":")== 0){
	varO[0] = 0;
	fscanf(fp, "%s", varO);
	}
	a = getNum(varTemp, headIn);
	b = getNum(varTemp2, headIn);
	out = getOutNum(varO, headOut);
if( (a == -1) && (b == -1) && (out == -1)){ // temp temp --> temp
	temp = getTempNum(varTemp,passIn);
	temp2 = getTempNum(varTemp2,passIn);
	tabAnswer = (NAND(temp, temp2));
	insertPass(tabAnswer, varO);
}
else if( (a != -1) && (b != -1) && (out != -1)){ // real real --> real
	tabAnswer = (NAND(truthtable[i-1][a-1], truthtable[i-1][b-1]));

	insertNum(tabAnswer, varO, headOut);
}
else if( (a != - 1) && (b== -1) && (out != -1)){     // real temp --> real
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (NAND(truthtable[i-1][a-1], temp2));

	insertNum(tabAnswer, varO, headOut);
}
else if( (a == -1) && (b!= -1) && (out != -1)){ // temp real --> real
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (NAND(temp, truthtable[i-1][b-1]));

	insertNum(tabAnswer, varO, headOut);
}
else if ( (a== -1) && (b == -1) && (out != -1)){ // temp temp --> real
	temp = getTempNum(varTemp, passIn);
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (NAND(temp, temp2));

	insertNum(tabAnswer, varO, headOut);
}
else if ( (a!= -1) && (b != -1) && (out == -1)){ // real real --> temp
	tabAnswer = (NAND(truthtable[i-1][a-1], truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);}
else if ( (a != -1) && (b == -1) && (out == -1)){ // real temp --> temp
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (NAND(truthtable[i-1][a-1], temp2));
	insertPass(tabAnswer, varO); 
}
else if ( (a == -1) && (b != -1) && (out == -1)){ // temp real --> temp
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (NAND(temp, truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);
}
}
else if(strcmp(instruct, "NOR") == 0){
	fscanf(fp, "%s %s", varTemp, varTemp2);
	fscanf(fp, "%s", varO);
        
	if(strcmp(varO, ":")== 0){
	varO[0] = 0;
	fscanf(fp, "%s", varO);
	}
	a = getNum(varTemp, headIn);
	b = getNum(varTemp2, headIn);
	out = getOutNum(varO, headOut);
if( (a == -1) && (b == -1) && (out == -1)){ // temp temp --> temp
	temp = getTempNum(varTemp,passIn);
	temp2 = getTempNum(varTemp2,passIn);
	tabAnswer = (NOR(temp, temp2));
	insertPass(tabAnswer, varO);
}
else if( (a != -1) && (b != -1) && (out != -1)){ // real real --> real
	tabAnswer = (NOR(truthtable[i-1][a-1], truthtable[i-1][b-1]));

	insertNum(tabAnswer, varO, headOut);
}
else if( (a != - 1) && (b== -1) && (out != -1)){     // real temp --> real
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (NOR(truthtable[i-1][a-1], temp2));

	insertNum(tabAnswer, varO, headOut);
}
else if( (a == -1) && (b!= -1) && (out != -1)){ // temp real --> real
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (NOR(temp, truthtable[i-1][b-1]));

	insertNum(tabAnswer, varO, headOut);
}
else if ( (a== -1) && (b == -1) && (out != -1)){ // temp temp --> real
	temp = getTempNum(varTemp, passIn);
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (NOR(temp, temp2));
	
	tabAnswer = (NOR(truthtable[i-1][a-1], truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);}
else if ( (a != -1) && (b == -1) && (out == -1)){ // real temp --> temp
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (NOR(truthtable[i-1][a-1], temp2));
	insertPass(tabAnswer, varO); 
}
else if ( (a == -1) && (b != -1) && (out == -1)){ // temp real --> temp
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (AND(temp, truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);
}
}
else if(strcmp(instruct, "XOR") == 0){
	fscanf(fp, "%s %s", varTemp, varTemp2);
	fscanf(fp, "%s", varO);
	
	if(strcmp(varO, ":")== 0){
	varO[0] = 0;
	fscanf(fp, "%s", varO);
	}
	a = getNum(varTemp, headIn);
	b = getNum(varTemp2, headIn);
	out = getOutNum(varO, headOut);
if( (a == -1) && (b == -1) && (out == -1)){ // temp temp --> temp
	temp = getTempNum(varTemp,passIn);
	temp2 = getTempNum(varTemp2,passIn);
	tabAnswer = (XOR(temp, temp2));
	insertPass(tabAnswer, varO);
}
else if( (a != -1) && (b != -1) && (out != -1)){ // real real --> real
	tabAnswer = (XOR(truthtable[i-1][a-1], truthtable[i-1][b-1]));
	insertNum(tabAnswer, varO, headOut);
}
else if( (a != -1) && (b== -1) && (out != -1)){     // real temp --> real
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (XOR(truthtable[i-1][a-1], temp2));
	insertNum(tabAnswer, varO, headOut);
}
else if( (a == -1) && (b!= -1) && (out != -1)){ // temp real --> real
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (XOR(temp, truthtable[i-1][b-1]));
	insertNum(tabAnswer, varO, headOut);
}
else if ( (a== -1) && (b == -1) && (out != -1)){ // temp temp --> real
	temp = getTempNum(varTemp, passIn);
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (XOR(temp, temp2));
	insertNum(tabAnswer, varO, headOut);
}
else if ( (a!= -1) && (b != -1) && (out == -1)){ // real real --> temp
	tabAnswer = (XOR(truthtable[i-1][a-1], truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);}
else if ( (a != -1) && (b == -1) && (out == -1)){ // real temp --> temp
	temp2 = getTempNum(varTemp2, passIn);
	tabAnswer = (XOR(truthtable[i-1][a-1], temp2));
	insertPass(tabAnswer, varO); 
}
else if ( (a == -1) && (b != -1) && (out == -1)){ // temp real --> temp
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (XOR(temp, truthtable[i-1][b-1]));
	insertPass(tabAnswer, varO);
}
}

else if(strcmp(instruct, "PASS") == 0){
	fscanf(fp, "%s", varTemp);
	in = getNum(varTemp, headIn);
	
	fscanf(fp, "%s", varO);
	if(strcmp(varO, ":")== 0){
	varO[0] = 0;
	fscanf(fp, "%s", varO);
	}
	
	out = getOutNum(varO, headOut);

if ( (in == -1) && (out == -1)){ // temp --> temp 
	temp = getTempNum(varTemp, passIn);
	insertPass(temp, varO);
} 
else if( (in != -1) && (out != -1)){ // real --> real
	tabAnswer = (PASS(truthtable[i-1][in-1]));
	insertNum(tabAnswer, varO, headOut);
}
else if((in == -1) && (out != -1)){ // temp --> real
	temp = getTempNum(varTemp, passIn);
	tabAnswer = (PASS(temp));
	insertNum(tabAnswer, varO, headOut);
}
else if ((in != -1) && (out == -1)){ // real --> temp
	tabAnswer = (PASS(truthtable[i-1][in-1]));
	insertPass(tabAnswer, varO);
}
}


//reset//
varTemp[0] = 0;
varTemp2[0] = 0;
instruct[0] = 0;
count++;
//memset(instruct, 0, sizeof(instruct));//	
}
temp = 1;
temp2 = 1;
passIn = NULL;
printAnswer(bit, numIn, truthtable, headOut,it);
it++;
count = 0;
// set position back to the 3rd line
fsetpos(fp, &pos);
}
  
fclose(fp);
return 0;


}
