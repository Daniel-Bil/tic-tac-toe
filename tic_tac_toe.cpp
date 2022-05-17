#include <iostream>
#include <vector>

using namespace std;

void mozliwy_ruch(int tab[3][3])
{
	for(int i =0; i<3;i++){
		for( int j = 0; j<3;j++)
			{
				cout<<"["<<j+1 + i*3<<"]";
					
			}
		cout<<endl;
	}
}

class Plansza
{
	public:
		int tab[3][3];
		void fill(int tab[][3])
		{			
			for(int i =0; i<3;i++){
				for( int j = 0; j<3;j++)
				{
					this->tab[i][j] = 0;
				}
			}
		}
		void pokaz()
		{	
			for(int i =0; i<3;i++){
				for( int j = 0; j<3;j++)
				{
					int wartosc = tab[i][j];
					if(wartosc == 1){
					
					cout<<"[X]";
					}
					else if(wartosc == 2)
					cout<<"[O]";
					else
					cout<<"[ ]";
				}
				cout<<endl;
			}
		}
		bool wygrana()
		{
			for(int i=0;i<3;i++)
			{
				int suma1 = 0;
				int suma2 = 0;
				for( int j = 0;j<3;j++)
				{
					if (tab[i][j]==1)
						suma1++;
					if (tab[i][j]==2)
						suma2++;						
				}
				if(suma1 == 3 or suma2 == 3)
					return true;
				suma1 = 0; suma2 = 0;
				for( int j = 0;j<3;j++)
				{
					if (tab[j][i]==1)
						suma1++;
					if (tab[j][i]==2)
						suma2++;						
				}
				if(suma1 == 3 or suma2 == 3)
					return true;
				suma1 = 0; suma2 = 0;
				for( int j = 0;j<3;j++)
				{
					if (tab[j][j]==1)
						suma1++;
					if (tab[j][j]==2)
						suma2++;						
				}
				if(suma1 == 3 or suma2 == 3)
					return true;
				suma1 = 0; suma2 = 0;
				for( int j = 0;j<3;j++)
				{
					if (tab[j][2-j]==1)
						suma1++;
					if (tab[j][2-j]==2)
						suma2++;						
				}
				if(suma1 == 3 or suma2 == 3)
					return true;
			}
			return false;
		}
			
};

int main(){

	
	Plansza plansza;
	
	plansza.fill(plansza.tab);
	int gracz = 0,wartosc;
	int x = 0, y = 0;
	while(true){
		
		do
		{	
			cout<<"Podaj miejsce"<<endl;
			
			mozliwy_ruch(plansza.tab);
			
			cin>>wartosc;
			x = wartosc/3;
			y = wartosc-(x*3)-1;
		}while(!(wartosc >= 1 && wartosc <= 9) or !(plansza.tab[x][y]==0));
		system("cls"); 
		
		if (gracz == 0)
		{
			plansza.tab[x][y] = 1;
		}
		else
		{
			plansza.tab[x][y] = 2;
		}
		if (plansza.wygrana()){
			cout<<"wygral gracz nr " << gracz<<endl;
			break;
		}
		
		gracz++;
		if(gracz%2 == 0)
		gracz = 0;
		plansza.pokaz();		
	}
	


	return 0;
}
