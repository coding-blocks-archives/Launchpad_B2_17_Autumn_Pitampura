#include<iostream>
#include<unordered_map>
using namespace std;


class node{
	public:

	char data;
	unordered_map<char,node*> m;
	bool isTerminal;

public:
	node(char d){
		data  = d;
		isTerminal = false;
	}

};

class trie{
	node*root;
public:
	trie(){
		root = new node('\0');
	}
	void addWord(char *word){

		node*temp = root;

		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->m.count(ch)==0){
				node*child = new node(ch);
				temp->m[ch] = child;
				temp = child;
			}
			else{
				temp = temp->m[ch];
			}
		}
		temp->isTerminal = true;

	}
	bool searchWord(char *word){
		node*temp = root;

		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->m[ch]==0){
				return false;
			}
			else{
				temp = temp->m[ch];
			}

		}
		return temp->isTerminal;
	}

};

int main(){

	trie t;
	char words[100][10] = {"apple","ape","code","coder","news"};

	for(int i=0;i<5;i++){
		t.addWord(words[i]);
	}

	while(1){
		cout<<"Enter a word to search";
		char word[10];
		cin>>word;

		if(t.searchWord(word)){
			cout<<word<<" found !";
		}
		else{
			cout<<word<<" not found!";
		}
	}


	return 0;
}