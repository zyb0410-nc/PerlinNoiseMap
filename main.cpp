#include<iostream>
#include<fstream>
#include<cstring>
#include<random>
#include<vector>
using namespace std;
//Data
char terrain[128][128] = {'\0'};
string color[128][128] = {"30"};
vector<int> recordx;
vector<int> recordy;
//Functions
long GetNS()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME,&ts);
    return ts.tv_sec*1000000000+ts.tv_nsec;
}
int RealRandomNumberInScope(int min,int max)
{
    srand(GetNS());
	return min + rand() % (max - min + 1);
}
int RandomNumberInScope(int min,int max)
{
    return min + rand() % (max - min + 1);
}
void White()
{
	for(int i = 0;i < 128; i++)
	{
		for(int j = 0;j < 128;j++)
		{
			terrain[j][i] = ' ';
		}
	}
}
void Clean()
{
	system("clear");
}
void Show()
{
	for(int i = 0;i < 128;i++)
	{
		for(int j = 0;j < 128;j++)
		{
			cout<<"\033["<<color[i][j]<<"m"<<terrain[i][j]<<"\033[0m";
		}
		cout << endl;
	}
}
void GenerateTerrain(string type,int number,int size)
{
    for(int i = 0;i < number;i++)
    {
        int firstpointx = RandomNumberInScope(0,128);
        int firstpointy = RandomNumberInScope(0,128);
        color[firstpointy][firstpointx] = "33";
        int direction = 0;
        long long seed = 0;
        if(type == "desert")
        {
            cout << "desert seed >>>";
        }
        if(type  == "forest")
        {
            cout << "forest seed >>>";
        }
        if(type == "mountain")
        {
            cout << "mountain seed >>>";
        }
        cin >> seed;
        if(seed%4 != 0)
        {
            seed *= 4;
        }
        for(int j = 0;j < size;j++)
        {
            direction = RandomNumberInScope(0,seed);
            if(direction <= seed/4)
            {
                firstpointy++;
            }
            if(direction <= seed/4*2 && direction > seed/4)
            {
                firstpointy--;
            }
            if(direction <= seed/4*3 && direction > seed/4*2)
            {
                firstpointx++;
            }
            if(direction <= seed && direction > seed/4*3)
            {
                firstpointx--;
            }
            
            if(firstpointy >= 128)
            {
                firstpointy -= 63;
            }
            if(firstpointy <= 0)
            {
                firstpointy += 63;
            }
            if(firstpointx >= 128)
            {
                firstpointx -= 63;
            }
            if(firstpointx <= 0)
            {
                firstpointx += 63;
            }
            if(type == "desert")
            {
                if(color[firstpointy][firstpointx] != "32" && color[firstpointy][firstpointx] != "37")
                {
                    color[firstpointy][firstpointx] = "33";
                }
            }
            if(type == "mountain")
            {
                if(color[firstpointy][firstpointx] != "32" && color[firstpointy][firstpointx] != "33")
                {
                    color[firstpointy][firstpointx] = "37";
                }
            }
            if(type == "forest")
            {
                if(color[firstpointy][firstpointx] != "37" && color[firstpointy][firstpointx] != "33")
                {
                    color[firstpointy][firstpointx] = "32";
                }
            }
        }
    }
}
int main()
{
	Clean();
	White();
    
    for(int i = 0;i < 5;i++)
    {
        int firstpointx = RandomNumberInScope(0,128);
        int firstpointy = RandomNumberInScope(0,128);
        terrain[firstpointy][firstpointx] = '*';
        int direction = 0;
        long long seed = 0;
        cout << "seed >>>";
        cin >> seed;
        if(seed%4 != 0)
        {
            seed *= 4;
        }
        for(int j = 0;j < 6000;j++)
        {
            direction = RandomNumberInScope(0,seed);
            if(direction <= seed/4)
            {
                firstpointy++;
            }
            if(direction <= seed/4*2 && direction > seed/4)
            {
                firstpointy--;
            }
            if(direction <= seed/4*3 && direction > seed/4*2)
            {
                firstpointx++;
            }
            if(direction <= seed && direction > seed/4*3)
            {
                firstpointx--;
            }
            
            if(firstpointy >= 128)
            {
                firstpointy -= 63;
            }
            if(firstpointy <= 0)
            {
                firstpointy += 63;
            }
            if(firstpointx >= 128)
            {
                firstpointx -= 63;
            }
            if(firstpointx <= 0)
            {
                firstpointx += 63;
            }
            terrain[firstpointy][firstpointx] = '*';
        }
    }
	/*
    GRASS green
    MOUTAIN grey
    DESERT/BEACH yellow
    */
    //完美种子：190291 913892 10291 389123 43 12092 3208 430 12 32228 2903 1290 3 10293 290184 29392 (ITS REALY GREAT!!!)

    Clean();

    GenerateTerrain("forest",4,2000);
    GenerateTerrain("mountain",6,500);
    GenerateTerrain("desert",1,1500);
    for(int i = 0;i < 128;i ++)
    {
        for(int j = 0;j < 128;j++)
        {
            if(terrain[i][j] == ' ')
            {
                color[i][j] = "30";
            }
        }
    }
    
    Show();

	return 0;
}
