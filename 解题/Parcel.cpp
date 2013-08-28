
/*#include<cstdio>

int main()
{
	int one, two, three, four, five, six;
	int count, threeCount, oneCount, twoCount;
	int oneParcel, twoParcel, threeParcel;
	scanf("%d%d%d%d%d%d", &one, &two, &three, &four, &five, &six);
	while(one != 0 || two !=0 || three !=0 || four != 0 || five !=0 || six !=0)
	{
		count = 0;
		count = six + five + four;
		oneParcel = 11*five;
		twoParcel = 5*four;

		if(three % 4 != 0)
		{
			threeCount = three/4 + 1;
			threeParcel = 4 - three%4;
		}
		else 
		{
			threeCount = three/4;
			threeParcel = 0;
		}
		count = count + threeCount;
		
		if(threeParcel == 1)
		{
			twoParcel = twoParcel + 1;
			oneParcel = oneParcel + 5;
		}
		else if(threeParcel == 2)
		{
			twoParcel = twoParcel + 3;
			oneParcel = oneParcel + 6;
		}
		else if(threeParcel == 3)
		{
			twoParcel = twoParcel + 5;
			oneParcel = oneParcel + 7;
		}
		
		if(two > twoParcel)
		{
			two = two - twoParcel;
			if(two % 9 != 0)
			{
				twoCount = two/9 + 1;
				oneParcel = oneParcel + (9 - two % 9)*4;
			}
			else 
			{
				twoCount = two/9;
			}
		}
		else
		{
			oneParcel = oneParcel + 4*(twoParcel - two);
			twoCount = 0;
		}
		
		if(one > oneParcel)
		{
			one = one - oneParcel;
			if(one % 36 != 0)
				oneCount = one/36 + 1;
			else
				oneCount = one/36;
		}
		else oneCount = 0;

		count = count + oneCount + twoCount;
		printf("%d\n", count);
		scanf("%d%d%d%d%d%d", &one, &two, &three, &four, &five, &six);
	}
	return 0;
}*/