#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//Data Array input Output &Temp
int input[1000][100];
int output[1000][100];
int temp[1000];
int cout[1000][100];
int allVals;
char unknown[1000][20];
char unknownCt[1000];
char totArgCt[1000];

int inCt = 0;
int outCt = 0;
int gateCt = 0;
int tempCt = 0;

char circuit[100][3000];
int steps;
int trutht[1000][100];
int logLevel = -1;

int power(int base, unsigned int exp) {
  int result = 1;
  for (int i = 0; i < exp; i++) {
    result *= base;
  }
  return result;
}

int grayCodeInt(int b1, int b2, int b3, int b4, int b5) {

	if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0)
		return 0;
	else if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 1)
		return 1;
	else if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 1 && b5 == 1)
		return 2;
	else if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 1 && b5 == 0)
		return 3;
	else if (b1 == 0 && b2 == 0 && b3 == 1 && b4 == 1 && b5 == 0)
		return 4;
	else if (b1 == 0 && b2 == 0 && b3 == 1 && b4 == 1 && b5 == 1)
		return 5;
	else if (b1 == 0 && b2 == 0 && b3 == 1 && b4 == 0 && b5 == 1)
		return 6;
	else if (b1 == 0 && b2 == 0 && b3 == 1 && b4 == 0 && b5 == 0)
		return 7;
	else if (b1 == 0 && b2 == 1 && b3 == 1 && b4 == 0 && b5 == 0)
		return 8;
	else if (b1 == 0 && b2 == 1 && b3 == 1 && b4 == 0 && b5 == 1)
		return 9;
	else if (b1 == 0 && b2 == 1 && b3 == 1 && b4 == 1 && b5 == 1)
		return 10;
	else if (b1 == 0 && b2 == 1 && b3 == 1 && b4 == 1 && b5 == 0)
		return 11;
	else if (b1 == 0 && b2 == 1 && b3 == 0 && b4 == 1 && b5 == 0)
		return 12;
	else if (b1 == 0 && b2 == 1 && b3 == 0 && b4 == 1 && b5 == 1)
		return 13;
	else if (b1 == 0 && b2 == 1 && b3 == 0 && b4 == 0 && b5 == 1)
		return 14;
	else if (b1 == 0 && b2 == 1 && b3 == 0 && b4 == 0 && b5 == 0)
		return 15;
	else if (b1 == 1 && b2 == 1 && b3 == 0 && b4 == 0 && b5 == 0)
		return 16;
	else if (b1 == 1 && b2 == 1 && b3 == 0 && b4 == 0 && b5 == 1)
		return 17;
	else if (b1 == 1 && b2 == 1 && b3 == 0 && b4 == 1 && b5 == 1)
		return 18;
	else if (b1 == 1 && b2 == 1 && b3 == 0 && b4 == 1 && b5 == 0)
		return 19;
	else if (b1 == 1 && b2 == 1 && b3 == 1 && b4 == 1 && b5 == 0)
		return 20;
	else if (b1 == 1 && b2 == 1 && b3 == 1 && b4 == 1 && b5 == 1)
		return 21;
	else if (b1 == 1 && b2 == 1 && b3 == 1 && b4 == 0 && b5 == 1)
		return 22;
	else if (b1 == 1 && b2 == 1 && b3 == 1 && b4 == 0 && b5 == 0)
		return 23;
	else if (b1 == 1 && b2 == 0 && b3 == 1 && b4 == 0 && b5 == 0)
		return 24;
	else if (b1 == 1 && b2 == 0 && b3 == 1 && b4 == 0 && b5 == 1)
		return 25;
	else if (b1 == 1 && b2 == 0 && b3 == 1 && b4 == 1 && b5 == 1)
		return 26;
	else if (b1 == 1 && b2 == 0 && b3 == 1 && b4 == 1 && b5 == 0)
		return 27;
	else if (b1 == 1 && b2 == 0 && b3 == 0 && b4 == 1 && b5 == 0)
		return 28;
	else if (b1 == 1 && b2 == 0 && b3 == 0 && b4 == 1 && b5 == 1)
		return 29;
	else if (b1 == 1 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 1)
		return 30;
	else if (b1 == 1 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0)
		return 31;
	return 0;

}

int parseStep(char* input, char cmd[1000][100])
{
	int i = 0;
	char str[3000];
	strcpy(str, input);
	char* item = strtok(str, " ");
	while (item != NULL)
	{
		strcpy(cmd[i++], item);
		if (logLevel == 100) printf("%d) %s\n", i - 1, item);
		item = strtok(NULL, " ");
	}

	return i;
}

int getInxFromName(char* input)
{
	int i;

	char* p = input;
	while (*p)
	{
		// While there are more characters to process...
		if (isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1))))
		{
			// Found a number
			i = strtol(p, &p, 10);	// Read number
		}
		else
		{
			// Otherwise, move on to the next character.
			p++;
		}
	}

	return i;
}

void reset()
{
	for (int i = 0; i < tempCt; i++)
	{
		temp[i] = 0;
	}

	for (int i = 0; i < allVals; i++)
	{
		for (int j = 0; j < outCt; j++)
		{
			cout[i][j] = 0;
		}
	}
}

void setData(char* op, int inx, int val)
{
	int ct = getInxFromName(op) - 1;
	if (op[0] == 'O')
	{
		cout[inx][ct] = val;
	}
	else if (op[0] == 't')
	{
		temp[ct] = val;
	}
}

int getData(char* op, int inx)
{
	int val = 0;

	int ct = getInxFromName(op) - 1;

	if (op[0] == 'I')
	{
		val = trutht[inx][ct];
	}
	else if (op[0] == 't')
	{
		val = temp[ct];
	}
	else
		val = ct + 1;

	return val;
}

int validateResults()
{
	for (int inx = 0; inx < allVals; inx++)
	{
		for (int i = 0; i < outCt; i++)
		{
			if (cout[inx][i] != output[inx][i])
				return -1;
		}
	}

	return 0;
}

int AND(int in1, int in2)
{
	if (in1 == 0 && in2 == 0)
	{
		return 0;
	}
	else if (in1 == 0 && in2 == 1)
	{
		return 0;
	}
	else if (in1 == 1 && in2 == 0)
	{
		return 0;
	}
	else if (in1 == 1 && in2 == 1)
	{
		return 1;
	}
	return 0;
}

int OR(int in1, int in2)
{
	if (in1 == 0 && in2 == 0)
	{
		return 0;
	}
	else if (in1 == 0 && in2 == 1)
	{
		return 1;
	}
	else if (in1 == 1 && in2 == 0)
	{
		return 1;
	}
	else if (in1 == 1 && in2 == 1)
	{
		return 1;
	}
	return 0;
}

int XOR(int in1, int in2)
{
	if (in1 == 0 && in2 == 0)
	{
		return 0;
	}
	else if (in1 == 0 && in2 == 1)
	{
		return 1;
	}
	else if (in1 == 1 && in2 == 0)
	{
		return 1;
	}
	else if (in1 == 1 && in2 == 1)
	{
		return 0;
	}
	return 0;
}

int NOT(int val)
{
	if (val == 0)
		return 1;
	else
		return 0;
}

int evaluateCircuit()
{
	char ops[1000][100];
	int opct;

	reset();
	for (int inx = 0; inx < allVals; inx++)
	{
		//printf("Circuit INX : %d\n", inx);
		for (int i = 0; i < steps; i++)
		{
			int uFlag = 0;
			if (logLevel == 0) printf("%d) %s\n", inx, circuit[i]);
			opct = parseStep(circuit[i], ops);
			totArgCt[i] = opct - 1;
			// resolve unknown
			if (ops[0][0] == 'G')
			{
				int gct = getInxFromName(ops[0]);
				if (logLevel == 0 || inx == logLevel) printf("unknown %d = %s\n", gct, unknown[gct - 1]);
				strcpy(ops[0], unknown[gct - 1]);
				uFlag = 1;
			}

			if (strcmp(ops[0], "AND") == 0)
			{
				int outval = AND(getData(ops[1 + uFlag], inx), getData(ops[2 + uFlag], inx));
				if (logLevel == 0 || inx == logLevel) printf("%d) %s %d,%d -> %d\n", inx, ops[0], getData(ops[1 + uFlag], inx), getData(ops[2 + uFlag], inx), outval);
				setData(ops[3 + uFlag], inx, outval);
			}
			else if (strcmp(ops[0], "OR") == 0)
			{
				int outval = OR(getData(ops[1 + uFlag], inx), getData(ops[2 + uFlag], inx));
				if (logLevel == 0 || inx == logLevel) printf("%d) %s %d,%d -> %d\n", inx, ops[0], getData(ops[1 + uFlag], inx), getData(ops[2 + uFlag], inx), outval);
				setData(ops[3 + uFlag], inx, outval);
			}
			else if (strcmp(ops[0], "XOR") == 0)
			{
				int outval = XOR(getData(ops[1 + uFlag], inx), getData(ops[2 + uFlag], inx));
				if (logLevel == 0 || inx == logLevel) printf("%d) %s %d,%d -> %d\n", inx, ops[0], getData(ops[1 + uFlag], inx), getData(ops[2 + uFlag], inx), outval);
				setData(ops[3 + uFlag], inx, outval);
			}
			else if (strcmp(ops[0], "NOT") == 0)
			{
				int outval = NOT(getData(ops[1 + uFlag], inx));
				if (logLevel == 0 || inx == logLevel) printf("%d) %s %d -> %d\n", inx, ops[0], getData(ops[1 + uFlag], inx), outval);
				setData(ops[2 + uFlag], inx, outval);
			}
			else if (strcmp(ops[0], "DECODER") == 0)
			{
				int mux = 0;

				int inps = atoi(ops[1]);
				if (inps == 6)
				{
					inps = 2;
					mux = 4;
				}
				else if (inps == 11)
				{
					inps = 3;
					mux = 8;
				}
				else if (inps == 20)
				{
					inps = 4;
					mux = 16;
				}
				else if (inps == 37)
				{
					inps = 5;
					mux = 32;
				}
				else if (inps == 2)
				{
					mux = 4;
				}
				else if (inps == 3)
				{
					mux = 8;
				}
				else if (inps == 4)
				{
					mux = 16;
				}
				else if (inps == 5)
				{
					mux = 32;
				}

				if (logLevel == 0 || inx == logLevel) printf("In Decoder  in %d out %d\n", inps, mux);
				//zero all outs
				for (int x = 0; x < mux; x++)
				{
					setData(ops[2 + inps + x], inx, 0);
				}

				int opval = 0;
				int inarr[5];
				for (int x = 0; x < 5; x++)
					inarr[x] = 0;

				for (int x = 0; x < inps; x++)
					inarr[4 - x] = getData(ops[1 + inps - x], inx);
				opval = grayCodeInt(inarr[0], inarr[1], inarr[2], inarr[3], inarr[4]);
				//if (logLevel == 0 || inx == logLevel) printf("OPVAL[%d] %s -> %d\n", opval, ops[1 + inps - x], getData(ops[1 + inps - x], inx));

				if (logLevel == 0 || inx == logLevel) printf("DEC OP : %s as %d\n", ops[2 + inps + opval], 1);
				setData(ops[2 + inps + opval], inx, 1);
			}
			else if (strcmp(ops[0], "MULTIPLEXER") == 0)
			{
				char tip[1000][100];
				char top[1000][100];
				int mux = 0;

				int inps = atoi(ops[1]);
				if (inps == 4)
				{
					mux = 2;
				}
				else if (inps == 8)
				{
					mux = 3;
				}
				else if (inps == 16)
				{
					mux = 4;
				}
				else if (inps == 32)
				{
					mux = 5;
				}
				else if (inps == 7)
				{
					inps = 4;
					mux = 2;
				}
				else if (inps == 12)
				{
					inps = 8;
					mux = 3;
				}
				else if (inps == 21)
				{
					inps = 16;
					mux = 4;
				}
				else if (inps == 38)
				{
					inps = 32;
					mux = 5;
				}

				for (int x = 0; x < inps; x++)
					strcpy(tip[x], ops[2 + x]);
				for (int x = 0; x < mux; x++)
					strcpy(top[x], ops[2 + inps + x]);
				int opval = 0;
				int inarr[5];
				for (int x = 0; x < 5; x++)
					inarr[x] = 0;
				for (int x = 0; x < mux; x++)
					inarr[4 - x] = getData(top[mux - x - 1], inx);
				opval = grayCodeInt(inarr[0], inarr[1], inarr[2], inarr[3], inarr[4]);
				if (logLevel == 0) printf("bit %d %d %d %d %d as %d\n", inarr[0], inarr[1], inarr[2], inarr[3], inarr[4], opval);

				for (int x = 0; x < mux; x++)
				{
					if (logLevel == 0) printf("MUX %s -> %d\n", top[x], getData(top[x], inx));
				}
				if (logLevel == 0) printf("OPVAL %s -> %d\n", tip[opval], opval);
				if (logLevel == 0) printf("OP %s [%d]-> %d\n", ops[2 + inps + mux], 2 + inps + mux, getData(tip[opval], inx));

				setData(ops[2 + inps + mux], inx, getData(tip[opval], inx));
			}
		}
	}

	return validateResults();
}

int solveGates(int gtloop)
{
	if (gtloop < gateCt)
	{
		if (unknownCt[gtloop] == 2)
		{
			strcpy(unknown[gtloop], "NOT");
			if (solveGates(gtloop + 1) == 0) return 0;
		}

		if (unknownCt[gtloop] == 3)
		{
			strcpy(unknown[gtloop], "OR");
			if (solveGates(gtloop + 1) == 0) return 0;
			strcpy(unknown[gtloop], "AND");
			if (solveGates(gtloop + 1) == 0) return 0;
			strcpy(unknown[gtloop], "XOR");
			if (solveGates(gtloop + 1) == 0) return 0;
		}

		if (unknownCt[gtloop] == 6 || unknownCt[gtloop] == 11 || unknownCt[gtloop] == 20 || unknownCt[gtloop] == 37)
		{
			strcpy(unknown[gtloop], "DECODER");
			if (solveGates(gtloop + 1) == 0) return 0;
		}

		if (unknownCt[gtloop] == 7 || unknownCt[gtloop] == 12 || unknownCt[gtloop] == 21 || unknownCt[gtloop] == 38)
		{
			strcpy(unknown[gtloop], "MULTIPLEXER");
			if (solveGates(gtloop + 1) == 0) return 0;
		}
	}
	else
	{
		return evaluateCircuit();
	}

	return -1;
}

int main(int argc, char* argv[])
{
	logLevel = -1;
	if (argc == 1)
	{
		printf("No Extra Command Line Argument Passed Other Than Program Name\n");
		return -1;
	}

	if (argc > 2)
	{
		printf("Too many arguments: %d where only 1 expected\n", argc);
		return -2;
	}

	//printf("file name : %s", argv[1]);

	FILE* dataFile;
	char str[3000];

	// open file
	dataFile = fopen(argv[1], "r");

	if (NULL == dataFile)
	{
		printf("file can't be opened \n");
		return -3;
	}

	inCt = 0;
	outCt = 0;
	steps = 0;
	char tmp[1000][100];
	int argctr = 0;
	while (fgets(str, 2500, dataFile) != NULL)
	{
		str[strcspn(str, "\r\n")] = '\0';
		if (logLevel == 0) printf("%s\n", str);
		argctr = parseStep(str, tmp);
		strcpy(circuit[steps], str);
		char* op, * nm, * val;
		op = tmp[0];
		if (strcmp(op, "INPUTVAR") == 0)
		{
			inCt = atoi(tmp[1]);
			allVals = power(2, inCt);
		}
		else
			if (strcmp(op, "OUTPUTVAR") == 0)
			{
				outCt = atoi(tmp[1]);
			}
			else
				if (strcmp(op, "OUTPUTVAL") == 0)
				{
					for (int i = 0; i < outCt; i++)
					{
						if (fgets(str, 2500, dataFile) != NULL)
						{
							str[strcspn(str, "\r\n")] = '\0';
							//printf("read %s\n", str);
							nm = strtok(str, " ");
							int col = getInxFromName(nm);
							col--;
							//printf("output %d for %s", col, nm);
							for (int j = 0; j < allVals; j++)
							{
								val = strtok(NULL, " ");
								output[j][col] = atoi(val);
								//printf("out%d= %d \n", j, output[col][j], val);
							}
						}
					}
				}
				else
				{
					int ctr = 0;
					// Gather all temps and Gates
					if (tmp[0][0] == 'G')
					{
						int i = getInxFromName(tmp[ctr++]);
						if (i > gateCt) gateCt = i;
						unknownCt[i - 1] = atoi(tmp[ctr++]);
						if (unknownCt[i - 1] == 2)
						{
							strcpy(unknown[i - 1], "NOT");
						}
						else if (unknownCt[i - 1] == 3)
						{
							strcpy(unknown[i - 1], "OR");
						}
						else
						{
							strcpy(unknown[i - 1], "MULTIPLEXER");
						}
					}

					for (int x = ctr; x < argctr; x++)
					{
						if (tmp[ctr][0] == 't')
						{
							int i = getInxFromName(tmp[ctr]);
							if (i > tempCt) tempCt = i;
						}
					}

					steps++;
				}
	}

	//printf("gates %d, temps %d\n", gateCt, tempCt);
	//fill truthtable - inputs
	for (int j = 0; j <= allVals; j++)
	{
		int gray = j ^ (j >> 1);
		for (int i = 0; i < inCt; i++) {
			trutht[j][inCt - i - 1] = 0;
		}
		for (int i = 0; i < inCt; i++) {
			trutht[j][inCt - i - 1] = gray % 2;
			gray /= 2;
		}
	}

	for (int i = 0; i < allVals; i++)
		for (int j = 0; j < outCt; j++)
		{
			trutht[i][inCt + j] = output[i][j];
		}

	if (solveGates(0) == 0)
	{
		for (int i = 0; i < gateCt; i++)
		{
			printf("G%d %s\n", i + 1, unknown[i]);
		}
	}
	else
		printf("INVALID\n");

	for (int i = 0; i < allVals; i++)
	{
		if (logLevel == 0) printf("%d : ", i);
		for (int j = 0; j < inCt + outCt; j++)
		{
			if (logLevel == 0) printf("%d ", trutht[i][j]);
		}

		if (logLevel == 0) printf(" COUT : ");

		for (int j = 0; j < outCt; j++)
		{
			if (logLevel == 0) printf("%d ", cout[i][j]);
		}

		if (logLevel == 0) printf("\n");
	}

	fclose(dataFile);
	return 0;
}
