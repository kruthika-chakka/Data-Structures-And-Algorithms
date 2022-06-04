#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int table_size = 31, old_table_size=0, total_collisions = 0;

// To check whether slot in array has already been filled
enum SlotStatus{
	full, empty
};

struct HashTableEntry {
      string e;
      enum SlotStatus info;
   };
   
struct HashTable {
      int tbl_size;
      HashTableEntry *item;
   };

//hash function to convert strings into ints : add ASCII values of each letter in the string and mod with table size
int hash_function(string str) 
{
    int i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % table_size;
}

bool is_prime_no(int n)
{
	int i;
	if (n == 2 || n == 3)
      return true;
   if (n == 1 || n % 2 == 0)
      return false;
   for (int i = 3; i * i <= n; i += 1)
    {
	  	if (n % i == 0)
        return false;
    }
   return true;
}

int next_prime_number(int ts)
{
   if (ts % 2 == 0)
      ts++;
   for (; !is_prime_no(ts); ts += 1);
      return ts;
}

int SearchKey(string k, int position, HashTable *ht) {
   
   int collisions = 0;
   while (ht->item[position].info != empty && ht->item[position].e != k) {
   		total_collisions += 1;
      position = position + (++collisions ^ 2) -1;
      if (position >= ht->tbl_size)
         position = position - ht->tbl_size;
   }
   return position;
}

void Insert(string k,int pos, HashTable *hash_t) {
	int position = SearchKey(k,pos, hash_t);
   if (hash_t->item[position].info != full) {
      hash_t->item[position].info = full;
      hash_t->item[position].e = k;
   }
}

HashTable *initiateTable(int tbl_size) {
   HashTable *ht;
   
   ht= new HashTable;
   if (ht == NULL) {
      cout<<"Out of Space"<<endl;
      return NULL;
   }
   ht->tbl_size = table_size;
   ht->item = new HashTableEntry [ht->tbl_size];

   for (int i = 0; i < ht->tbl_size; i++) {
      ht->item[i].info = empty;
      ht->item[i].e = "";
   }
   return ht;
}

HashTable *Rehash(int tbl_s, HashTable *ht) {
   
   HashTableEntry *t= ht->item;
   ht = initiateTable(table_size);
   for (int i = 0; i < tbl_s; i++) {
      if (t[i].info == full)
         Insert(t[i].e, hash_function(t[i].e), ht);
   }
   return ht;
}

void display(HashTable *ht) {
	cout << "Hash Table:" << endl;
   for (int i = 0; i < ht->tbl_size; i++) {
      string wrd = ht->item[i].e;
      if (wrd == "")
         cout << i + 1 << ". Null" << endl;
      else
         cout << i + 1 << ". " << wrd << endl;
   }
}

int main()
{
	string word="";
	ifstream inFile;
	int hash_val=0;
	double lambda=0,word_count=0;
	bool table_size_changed = false;
	HashTable *hash_table;
	 
	//Change input file name her if required
	inFile.open("words.txt");
	 if (!inFile) {				// Error handler for file opener
        cout << "Unable to open file";
        return 1;
    }
    
    // initiate hash table
    hash_table = initiateTable(table_size);
    
    while (inFile >> word) {
		// keep count of number of words
    	word_count += 1;
    	lambda = word_count / table_size;
    	
    	// if lambda >= 0.5 change table size
		if (lambda >= 0.5)
		{
			display(hash_table);
    		cout << "Table becomes small for hashing" << endl
    			<< "Table size will be doubled to next prime number.";
    		old_table_size = table_size;
    		table_size = next_prime_number(old_table_size * 2);
    		
			// rehash
			
    		hash_table = Rehash(old_table_size, hash_table);
		}
		
    	hash_val = hash_function(word); // Hash value of each word
		
    	//Need to hash here
    	Insert(word,hash_val, hash_table);
	}
    
    inFile.close();
    cout << "File closed";
    cout << "Hash Table:" <<endl;
    display(hash_table);
    cout << "Total number of collisions: " << total_collisions;
    
    return 0;
	
}
