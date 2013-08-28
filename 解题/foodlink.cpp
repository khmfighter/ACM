
#include<iostream>
using namespace std;

#define MAX_OF_ANIMAL 50001

int main()
{
	int number_of_amimal, number_of_words;
	int animal[MAX_OF_ANIMAL] = {0};
	int type, x, y;
	int number_of_lie = 0;

	cin>>number_of_amimal>>number_of_words;
	for(int i = 0; i < number_of_words; i++)
	{
		cin>>type>>x>>y;
		if(x > number_of_animal || y > number_of_animal)
		{
			number_of_lie++;
			continue;
		}

		if(type == 2 && x == y)
		{
			number_of_lie++;
			continue;
		}

		if(x != y)
		{
			
		}
	}


}