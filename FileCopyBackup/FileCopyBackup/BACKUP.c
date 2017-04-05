//Charlie Ang
//CSC 3350 Spring 2016
//April 4, 2016
//Lab 2 BACKUP
//This program copies a specified file and creates a backup
//copy of the file with a different name.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	FILE *filein;
	FILE *fileout;

	int i;
	int ch = ' ';
	int sourceLength = 0;	//length of source 

	char sourceFilename[100]; //pointer to [] for storing source filename    
	char stringOutput[100];	//output extension 

	for (i = 1; i < argc; i++)	//Find first filename on line.....
	{
		if (_stricmp(argv[i], "/?") == 0)	//Help message request switch 
		{
			printf("\nThis program copies a specified file and creates a backup copy of the file with a different name.\n");
			return 0;	//exit code 
		}
		else
		{
			if (freopen_s(&filein, argv[i], "rb", stdin) == 0)	//rb for reading in binary mode
			{
				printf("Copying %s into ", argv[i]);
				break;
			}
			printf("Error: Invalid filename %s\n", argv[i]);	//print out error message if file cannot be opened 
			return 0;	//quit program
		}
	}

	//NO COMMANDS GIVEN
	if (argc == 1)	//if no source file is specified -->BACKUP
	{
		printf("\nSource file must be specified.\n"); //if filename is invalid
		return 0;	//quit program
	}

	//ARGC == 2 one argument count for source --> BACKUP SRC
	else if (argc == 2)
	{
		fopen_s(&filein, argv[i], "rb");	//open source file
		sourceLength = strlen(argv[i]) + 1;	//length of source length 
		strcpy_s(sourceFilename, 100, argv[i]);	//copy source filename into sourceFileName cstring array

		//Manipulate source filename by removing the extension
		for (int i = sourceLength; i >= 0; i--)	//starting from end of array and going until finding first '.'
		{
			if (sourceFilename[i] == '.')
			{
				sourceFilename[i] = 0;	//append null byte to remove extesnion
				break;
			}
		}

		strcat_s(sourceFilename, 100, ".bak");	//concatenate ".bak" to end of sourceFilename to get destination path

		fopen_s(&fileout, sourceFilename, "wb");	//open output file using wb for writing binary

		if (fileout == NULL)
		{
			printf("\nCannot open target file.\n");	//output error message
			fclose(fileout);
			//exit(1);
			return 0;
		}

		while (ch != EOF)
		{
			//ch = getchar();
			ch = getc(filein);	//read character from source file

			if (ch == EOF)
			{
				break;	//break out of while loop if EOF is reached
			}
			else
			{
				//putchar(ch)
				fputc(ch, fileout);	//wirte character from source file to destination (output) file
			}
		}
		printf("%s.\n", sourceFilename);	//prints destination filename
	}
	else if (argc == 3) //two argument count...one for source and other for destination -->BACKUP SRC DEST
	{
		fopen_s(&filein, argv[i], "rb");	//open source file
		sourceLength = strlen(argv[i]) + 1;	//length of source length
		strcpy_s(sourceFilename, 100, argv[i]);	//copy source filename into sourceFileName cstring array  C:\Users\....
		strcpy_s(stringOutput, 100, argv[i + 1]);	//destination filename

		fopen_s(&fileout, stringOutput, "wb");	//open output file using wb for writing binary
		if (fileout == NULL)
		{
			printf("\nCannot open target file.\n");	//output error message
			fclose(fileout);
			//exit(1);
			return 0;
		}

		while (ch != EOF)
		{
			//ch = getchar();
			ch = getc(filein);	//read character from source file

			if (ch == EOF)
			{
				break;	//break out of while loop if EOF is reached
			}
			else
			{
				//putchar(ch)
				fputc(ch, fileout);	//wirte character from source file to destination (output) file
			}
		}
		printf("%s.\n", stringOutput);	//prints destination filename
	}

	else //too many argument calls. If more than 3 argument calls
	{
		printf("\nToo many argument calls were made. Please specify a source filename and a destination filename.\n");
		return 0;	//quit program
	}

	fclose(filein);	//close source file
	fclose(fileout);	//close destination file

	//system("pause");
	return 0;
}