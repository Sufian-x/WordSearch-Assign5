#include<iostream>
#include<fstream>

using namespace std;
class PuzzleGrid
{
private:
	char** Words; //Store words form file
	int wordCount;
	int Rows,Cols;
	char** GRID; //Array to store grid
public:
	void InputFile();
	void WordPlacer();
	int StringLenght(char str[]);
	void Output();
};

int PuzzleGrid::StringLenght(char str[])
{
	int stringLen = 0;
	int i;
	for (i=0; str[i] != '\0'; i++)
	{
		stringLen++;
	} 
	return stringLen;
}

void PuzzleGrid::InputFile()
{
	ifstream input;
	char name[25];
	cout<<"Enter file name which contains the words stored in it !!\n";
	cin>>name;
	input.open(name);
	if(input.is_open())
	{
		cout<<"Enter number of words stored in the file !!\n";
		cin>>wordCount;
		cout<<"Enter Rows of the desired Grid : ";
		cin>>Rows;
		GRID=new char*[Rows];
		cout<<"Enter Columns of the desired Grid : ";
		cin>>Cols;
		for(int i=0;i<Rows;i++)
		{
			GRID[i]=new char[Cols];
		}
		char Word[15];
		Words=new char*[wordCount];
		int Size,k;
		for(int i=0;i<=wordCount;i++)
		{
			Size=0,k=0;
			input.getline(Word,15);
			while(Word[k]!='\0')
			{
				Size++;
				k++;
			}
			k=0;
			Words[i]=new char[Size+1];
			
			for(int j=0;j<Size;j++)
			{
				Words[i][j]=Word[j];
			}
			Words[i][Size]='\0';
		}
		cout<<"The words in file are:\n";
		for(int j=0;j<=wordCount;j++)
			{
				cout<<Words[j];
				cout<<endl;
			}
		input.close();
	}
	else
	{
		cout<<"FILE NOT FOUND !!!!!!!\n\n";
	}
	
}

void PuzzleGrid::WordPlacer()
{
	int counter=0;
	for(int i=0;i<Rows;i++)
	{
		for(int j=0;j<Cols;j++)		//Placing dots at every position
		{
			GRID[i][j]=0;
		}
	}
	//for(int i=0;i<Rows;i++)
	//{
	//	for(int j=0;j<Cols;j++)		//Placing dots at every position
	//	{
	//		cout<<GRID[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	
	unsigned int r,c,len,placedWords=0,now=1;
	for(int i=placedWords;i<wordCount;)
	{
		len=PuzzleGrid::StringLenght(Words[now]);

			r=rand()%Rows;		//random number generates and places the word at that position
			c=rand()%Cols;		// r = row , c = columns
			
			if(c+len<=Cols)
			{	
				for(int k=c,j=r;k<c+len;k++)
				{
					if(GRID[j][k]==0)
					{
						counter++;
					}
				}
				if(counter==len)
				{
					for(int k=0,j=c,i=r;k<len;k++,j++)
					{
						GRID[i][j]=Words[now][k];
						
					}
					wordCount++;
					now++;
				}
				counter=0;
			}

			len=PuzzleGrid::StringLenght(Words[now]);
			r=rand()%Rows;		//random number generates and places the word at that position
			c=rand()%Cols;		// r = row , c = columns
			
			if(r+len<=Rows)
			{	
				for(int k=c,j=r;j<r+len;j++)
				{
					if(GRID[j][k]==0)
					{
						counter++;
					}
				}
				if(counter==len)
				{
					for(int k=0,j=c,i=r;k<len;k++,i++)
					{
						GRID[i][j]=Words[now][k];
						
					}
					wordCount++;
					now++;
				}
				counter=0;
			}

			len=PuzzleGrid::StringLenght(Words[now]);
			r=rand()%Rows;		//random number generates and places the word at that position
			c=rand()%Cols;		// r = row , c = columns
			
			if(r-len>=0)
			{	
				for(int k=c,j=r;j<r+len;j--)
				{
					if(GRID[j][k]==0)
					{
						counter++;
					}
				}
				if(counter==len)
				{
					for(int k=0,j=c,i=r;k<len;k++,i--)
					{
						GRID[i][j]=Words[now][k];
						
					}
					wordCount++;
					now++;
				}
				counter=0;
			}

			len=PuzzleGrid::StringLenght(Words[now]);
			r=rand()%Rows;		//random number generates and places the word at that position
			c=rand()%Cols;		// r = row , c = columns
			
			if(c-len>=0)
			{	
				for(int k=c,j=r;j<r+len;j--)
				{
					if(GRID[j][k]==0)
					{
						counter++;
					}
				}
				if(counter==len)
				{
					for(int k=0,j=c,i=r;k<len;k++,i--)
					{
						GRID[i][j]=Words[now][k];
						
					}
					wordCount++;
					now++;
				}
				counter=0;
			}
	}
	cout<<"\n\t****** THE GRID IS CREATED *****\n\n";

	//Placing random alphabets 
	int k=1;
	char alphabets[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
	for(int i=0;i<Rows;i++)
	{
		for(int j=0;j<Cols;j++)
		{
			if(GRID[i][j]=='.')
			{
				GRID[i][j]=alphabets[k];
				k++;
			}
			if(k>=26)
			{
				k=0;
			}
		}
	}
	for(int i=0;i<Rows;i++)			//for display on console
	{
		for(int j=0;j<Cols;j++)
		{
			cout<<GRID[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

//Places grid in the file
void PuzzleGrid::Output()
{
	char name[25];
	cout<<"Enter file name where the results needs to be placed !!\n";
	cin>>name;
	ofstream output(name);
	for(int i=0;i<Rows;i++)
	{
		for(int j=0;j<Cols;j++)
		{
			output<<GRID[i][j]<<" ";
		}
		output<<"\n";
	}

}
class WordFinder
{
private:
	char** Words; //Store the words in the grid
	char** WordstoFind; // stores the words entered by user
	int Rows,Cols,testCases;
	int StartPoints[2]; //to store starting index of the word
	int EndPoints[2];//to store ending index of the word

public:

	void InputFile();
	void wordFinder();
	int StringLenght(char* str); // returns length of the word passed
	//These functions checks the possible positions of the word
	bool Righttoleft(int );
	bool LefttoRight(int );
	bool ToptoBottom(int );
	bool BottomtoTop(int );
	bool DiagTRtoBL(int );
	bool DiagBLtoTR(int );
	bool DiagBRtoTL(int );
	bool DiagTLtoBR(int );

};


void WordFinder::InputFile()
{
	ifstream input;
	char name[25];
	cout<<"Enter file name which has the grid stored in it !!\n";
	cin>>name;
	input.open(name);
	if(input.is_open())
	{
		cout<<"Enter Rows of the Grid : ";
		cin>>Rows;
		cout<<"Enter Columns of the Grid : ";
		cin>>Cols;
		cout<<"Enter Number of test cases : ";
		cin>>testCases;
		Words=new char*[Rows];					//Making rows of dynamic array
		
		for(int i=0;i<Rows;i++)
		{
			Words[i]=new char[Cols];			//Making columns of dynamic array 
		}
		for(int i=0;i<Rows;i++)
		{
			for(int j=0;j<Cols;j++)
			{
				input>>Words[i][j];
			}	
		}
		for(int i=0;i<Rows;i++)
		{
			for(int j=0;j<Cols;j++)
			{
				cout<<Words[i][j]<<" ";
				
			}
			cout<<endl;
		}

		for(int i=0;i<testCases;i++)
		{
			WordstoFind = new char*[testCases];			//Array that stores the words to find
		}
		cout<<"\n\nEnter the words you want to find (in capital letters): \n";
		char line[20];
		int temp;
		for(int i=0;i<=testCases;i++)
		{
			cin.getline(line,20);
			temp=StringLenght(line);
			WordstoFind[i] = new char[temp+1];			// +1 for storing '\0'
			for(int j=0;j<temp;j++)
			{
				WordstoFind[i][j]=line[j];
			}
			WordstoFind[i][temp]='\0';
		}
		
	}
	else
	{
		cout<<"\nFILE NOT FOUND !!!!!!!\n\n";

	}
	
}

//This function checks if the words are present in grid and then outputs the result in the file
void WordFinder::wordFinder()
{
	int temp=1;
	char name[25];
	cout<<"Enter file name where the results needs to be placed !!\n";
	cin.getline(name,25);
	ofstream output(name);
	for(int i=0;i<testCases;i++)
	{
		if(Righttoleft(temp)==true)
		{
			cout<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";	
			output<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";

		}
		else if(LefttoRight(temp)==true)
		{
			cout<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";	
			output<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
		
		}
		else if(ToptoBottom(temp)==true)
		{
			cout<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";	
			output<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
				
		}
		else if(BottomtoTop(temp)==true)
		{
			cout<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
			output<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
		}
		else if(DiagBRtoTL(temp)==true)
		{
			cout<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
			output<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
		}
		else if(DiagTRtoBL(temp)==true)
		{
			cout<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
			
			output<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
		}
		else if(DiagBLtoTR(temp)==true)
		{
			cout<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
			output<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
		}
		else if(DiagTLtoBR(temp)==true)
		{
			cout<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
			output<<WordstoFind[temp]<<" is found at {"<<StartPoints[0]<<","<<StartPoints[1]<<"} , {"<<
			EndPoints[0]<<","<<EndPoints[1]<<"}\n";
		}
		else
		{
			cout<<endl<<WordstoFind[temp]<<" NOT FOUND";
			output<<WordstoFind[temp]<<" NOT FOUND";
		}
		temp++;
	}
		
}

//Following funtions checks the position of the words and return true if found
bool WordFinder::Righttoleft(int number)
{
	int temp = 0;
	int match = 0;

	int len = StringLenght(WordstoFind[number]);
	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			temp = 0;
			if (Words[i][j] == WordstoFind[number][temp])				
			{
				StartPoints[0] = i;						//Here the first word is matching, so storing its index					
				StartPoints[1] = j;	
				if (j - len < 0)							
				{
					StartPoints[0] = -1;
					StartPoints[1] = -1;
				}	
				else
				{
					int cord1 = j;

					for (temp = 0; temp < len; temp++, cord1--)		
						if (Words[i][cord1] == WordstoFind[number][temp])
							match++;
					if (match == len)
					{
						cord1++;
						EndPoints[0] = i;					
						EndPoints[1] = cord1;
						match = 0;

						return true;
					}
					else
					{
						match = 0;						
						StartPoints[0] = -1;
						StartPoints[1] = -1;
					}
				}
			}
		}
	}

	return false;
}

bool WordFinder::LefttoRight(int number)
{
	int temp = 0;
	int match = 0;

	int len = StringLenght(WordstoFind[number]);

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			temp = 0;
			if (Words[i][j] == WordstoFind[number][temp])				
			{
				StartPoints[0] = i;		//Here the first word is matching, so storing its index
				StartPoints[1] = j;
				if (j + len > Cols)					
				{
					StartPoints[0] = -1;
					StartPoints[1] = -1;
				}
				else
				{
					int cord1 = j;

					for (temp = 0; temp < len; temp++, cord1++)		//Comparing rest of word
						if (Words[i][cord1] == WordstoFind[number][temp])
							match++;
					if (match == len)
					{
						cord1--;
						EndPoints[0] = i;					
						EndPoints[1] = cord1;
						match = 0;

						return true;
					}
					else
					{
						match = 0;
						StartPoints[0] = -1;				
						StartPoints[1] = -1;
					}
				}
			}
		}
	}

	return false;
}

bool WordFinder::ToptoBottom(int number)
{int temp = 0;
	int match = 0;

	int len = StringLenght(WordstoFind[number]);

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			temp = 0;
			if (Words[i][j] == WordstoFind[number][temp])				//Here the first word is matching, so storing its index
			{
				StartPoints[0] = i;
				StartPoints[1] = j;
				if (i + len > Rows)				
				{
					StartPoints[0] = -1;
					StartPoints[1] = -1;
				}
				else
				{
					int cord = i;

					for (temp = 0; temp < len; temp++, cord++)		
						if (Words[cord][j] == WordstoFind[number][temp])
							match++;
					if (match == len)
					{
						cord--;
						EndPoints[0] = cord;					
						EndPoints[1] = j;
						match = 0;

						return true;
					}
					else
					{
						match = 0;
						StartPoints[0] = -1;				
						StartPoints[1] = -1;
					}
				}
			}
		}
	}

	return false;
}

bool WordFinder::BottomtoTop(int number)
{
	int temp = 0;
	int match = 0;

	int len = StringLenght(WordstoFind[number]);

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			temp = 0;
			if (Words[i][j] == WordstoFind[number][temp])				//Here the first word is matching, so storing its index
			{
				StartPoints[0] = i;
				StartPoints[1] = j;
				if (i - len < 0)							
				{
					StartPoints[0] = -1;
					StartPoints[1] = -1;
				}
				else
				{
					int cord = i;

					for (temp = 0; temp < len; temp++, cord--)		//Comparing rest of word
						if (Words[cord][j] == WordstoFind[number][temp])
							match++;
					if (match == len)
					{
						cord++;
						EndPoints[0] = cord;					
						EndPoints[1] = j;
						match = 0;

						return true;
					}
					else
					{
						match = 0;
						StartPoints[0] = -1;				
						StartPoints[1] = -1;
					}
				}
			}
		}
	}

	return false;
}

bool WordFinder::DiagBRtoTL(int number)
{
	
	int temp = 0;
	int match = 0;

	int len = StringLenght(WordstoFind[number]);

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			temp = 0;
			if (Words[i][j] == WordstoFind[number][temp])					
			{
				StartPoints[0] = i;
				StartPoints[1] = j;
				if (i - len < 0 || j - len < 0)			
				{
					StartPoints[0] = -1;
					StartPoints[1] = -1;
				}
				else
				{
					int cord = i;
					int cord1 = j;

					for (temp = 0; temp < len; temp++, cord--, cord1--)		
						if (Words[cord][cord1] == WordstoFind[number][temp])
							match++;
					if (match == len)
					{
						cord++;
						cord1++;
						EndPoints[0] = cord;						
						EndPoints[1] = cord1;
						match = 0;

						return true;
					}
					else
					{
						match = 0;
						StartPoints[0] = -1;					
						StartPoints[1] = -1;
					}
				}
			}
		}
	}

	return false;
}

bool WordFinder::DiagTRtoBL(int number)
{int temp = 0;
	int match = 0;

	int len = StringLenght(WordstoFind[number]);

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			temp = 0;
			if (Words[i][j] == WordstoFind[number][temp])						
			{
				StartPoints[0] = i;
				StartPoints[1] = j;
				if (i + len > Rows || j - len < 0)		
				{
					StartPoints[0] = -1;
					StartPoints[1] = -1;
				}
				else
				{
					int cord = i;
					int cord1 = j;

					for (temp = 0; temp < len; temp++, cord++, cord1--)		
						if (Words[cord][cord1] == WordstoFind[number][temp])
							match++;
					if (match == len)
					{
						cord--;
						cord1++;
						EndPoints[0] = cord;							
						EndPoints[1] = cord1;
						match = 0;

						return true;
					}
					else
					{
						match = 0;
						StartPoints[0] = -1;						
						StartPoints[1] = -1;
					}
				}
			}
		}
	}

	return false;
}

bool WordFinder::DiagBLtoTR(int number)
{
	int temp = 0;
	int match = 0;

	int len = StringLenght(WordstoFind[number]);

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			temp = 0;
			if (Words[i][j] == WordstoFind[number][temp])						
			{
				StartPoints[0] = i;
				StartPoints[1] = j;
				if (i - len < 0 || j + len > Cols)		
				{
					StartPoints[0] = -1;
					StartPoints[1] = -1;
				}
				else
				{
					int cord = i;
					int cord1 = j;

					for (temp = 0; temp < len; temp++, cord--, cord1++)		
						if (Words[cord][cord1] == WordstoFind[number][temp])
							match++;
					if (match == len)
					{
						cord++;
						cord1--;
						EndPoints[0] = cord;						
						EndPoints[1] = cord1;
						match = 0;

						return true;
					}
					else
					{
						match = 0;
						StartPoints[0] = -1;						
						StartPoints[1] = -1;
					}
				}
			}
		}
	}

	return false;
}

bool WordFinder::DiagTLtoBR(int number)
{
	
	int temp = 0;
	int match = 0;

	int len = StringLenght(WordstoFind[number]);

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			temp = 0;
			if (Words[i][j] == WordstoFind[number][temp])							
			{
				StartPoints[0] = i;
				StartPoints[1] = j;
				if (i + len > Rows || j + len > Cols)		
				{
					StartPoints[0] = -1;
					StartPoints[1] = -1;
				}
				else
				{
					int cord = i;
					int cord1 = j;

					for (temp = 0; temp < len; temp++, cord++, cord1++)			
						if (Words[cord][cord1] == WordstoFind[number][temp])
							match++;
					if (match == len)
					{
						cord--;
						cord1--;
						EndPoints[0] = cord;							
						EndPoints[1] = cord1;
						match = 0;

						return true;
					}
					else
					{
						match = 0;
						StartPoints[0] = -1;							
						StartPoints[1] = -1;
					}
				}
			}
		}
	}

	return false;
}

int WordFinder::StringLenght(char* str)
{
	int stringLen = 0;
	for (char* temp = str; *temp != '\0'; temp++)
	{
		stringLen++;
	}
	return stringLen;
}


int main()
{
	char fileName[25];
	char Opt=0;			//Opt = Option
	cout<<"\t*******************************************************\n";
	cout<<"\t****** WELCOME TO WORD PUZZLE CREATOR AND FINDER ******\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t\t1) Create Grid\n\t\t2) Search Words from Grid\n\t\t3) Quit\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t*******************************************************\n\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t**********\tPress 'C' to create a grid\t*******\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t*** Press 'S' to Search words from an existing grid ***\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t**********\tPress 'Q' to Quit\t***************\n";
	cout<<"\t*******************************************************\n";
	cout<<"\t*******************************************************\n";
	cout<<"\n\nENTER YOUR CHOICE: ";
	while(Opt!='Q' ||  Opt!='q')
	{
		cin>>Opt;
		if(Opt=='Q' ||  Opt=='q')
		{
			cout<<"\nProgram is exiting. See you later :)\n\n\n\n";
			break;
		}
		if(Opt=='C' || Opt=='c')
		{
			PuzzleGrid puzzle;
			puzzle.InputFile();
			puzzle.WordPlacer();		
			puzzle.Output();
			cout<<"\n\nTHE WORDS HAVE BEEN WRITTEN IN FORM OF A GRID IN THE GIVEN FILE !!!!!\n\n\n";
			cout<<"PRESS Q to Exit or S to search a GRID: ";
		}
		else if(Opt=='S' || Opt=='s')
		{
			WordFinder Find;
			Find.InputFile();
			Find.wordFinder();
			cout<<"\n\nTHE WORDS HAVE BEEN FOUND AND ARE WRITTEN IN THE GIVEN FILE !!!!!\n\n\n";
			cout<<"PRESS Q to Exit or C to create a GRID: ";
		}
		else
		{	
			cout<<"WRONG WORD ENTERED. KINDLY SELECT A WORD FROM ABOVE CHOICES TO PURSUE\n";
		}
	}

	system("pause");
}