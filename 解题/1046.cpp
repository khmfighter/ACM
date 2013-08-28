

#include<cstdlib>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

struct RGB
{
	int red;
	int green;
	int blue;
};

#ifdef DEBUG
int compare_red(const void *a, const void *b)
{
	return ((RGB*)a)->red - ((RGB*)b)->red;
}

int compare_blue(const void *a, const void *b)
{
	return ((RGB*)a)->blue - ((RGB*)b)->blue;
}

int compare_green(const void *a, const void *b)
{
	return ((RGB*)a)->green - ((RGB*)b)->green;
}
#endif

int get_lowest_distance_index(int *distance, int n)
{
#ifdef DEBUG
	qsort(rgb, n, sizeof(int), compare_blue);
	qsort(rgb, n, sizeof(int), compare_green);
	qsort(rgb, n, sizeof(int), compare_red);
#endif

	int min = 0;
	for(int i = 1; i < n; i++)
	{
		if(distance[i] < distance[min])
		{
			min = i;
		}
	}

	return min;
}

int computer_distance(const RGB *rgb1,const RGB *rgb2)
{
	return (rgb1->red - rgb2->red)*(rgb1->red - rgb2->red) + (rgb1->blue - rgb2->blue)*(rgb1->blue - rgb2->blue) + (rgb1->green - rgb2->green)*(rgb1->green - rgb2->green);
}

/*int main()
{
	vector<RGB> vector_rgb;
	RGB rgb, rgb_16[16];
	int in_red, in_green, in_blue;
	int min_index;
	int distance[16];
	int i = 0;

	while(i < 16)
	{
		cin>>in_red;
		cin>>in_green;
		cin>>in_blue;

		rgb.red = in_red;
		rgb.green = in_green;
		rgb.blue = in_blue;

		rgb_16[i] = rgb;
		i++;
	}
	while(true)
	{
		cin>>in_red;
		cin>>in_green;
		cin>>in_blue;

		rgb.red = in_red;
		rgb.green = in_green;
		rgb.blue = in_blue;

		if(in_red == -1)
			break;
		vector_rgb.push_back(rgb);
	}

	for(i = 0; i < vector_rgb.size(); i++)
	{
		for(int j = 0; j < 16; j++)
		{
			distance[j] = computer_distance(&vector_rgb[i], &rgb_16[j]);
		}
		min_index = get_lowest_distance_index(distance, 16);
		cout<<"("<<vector_rgb[i].red<<", "<<vector_rgb[i].green<<", "<<vector_rgb[i].blue<<")";
		cout<<" maps to "<<"("<<rgb_16[min_index].red<<", "<<rgb_16[min_index].green<<", "<<rgb_16[min_index].blue<<")"<<endl;
	}

	return 0;*/

/*	RGB rgb1, rgb2;
	rgb1.red = 0;
	rgb1.green = 0;
	rgb1.blue = 0;

	rgb2.red = 1;
	rgb2.green = 1;
	rgb2.blue = 1;

	printf("%d\n", computer_distance(&rgb1, &rgb2));
	return 0;
}*/