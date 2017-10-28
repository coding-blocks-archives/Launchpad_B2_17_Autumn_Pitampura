#include<iostream>
#include<unordered_map>
using namespace std;

/*
class Fruit{

	price;
	color;
	sweetness;
	state;
	id;
	vendor;
}
*/

int main(){

	auto x = 1LL;

	unordered_map<string,Fruit > h;

	h["Mango"]  = 100;
	h["Mango"] = 80;
	cout<<h["Mango"]<<endl;

	//More ways
	h.insert(make_pair("Kiwi",170));

	//Exist 
	string f;
	cin>>f;
	if(h.count(f)){
		cout<<"Fruit costs"<<h[f]<<endl;
	}
	else{
		cout<<"Fruit doesn't exist";
	}

	//Print all the elements
	for(auto p:h){
		cout<<p.first<<" and "<<p.second<<endl;
	}


 
	return 0;
}