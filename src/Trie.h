#include <string>

#ifndef TRIE_H
#define TRIE_H
struct end_node {
    int original_seq_index;
    int current_seq_index;
};

struct trie_node {
    char base;
    long count;
    trie_node *links[5]; // array of pointers to trie nodes
    end_node *end;
};

///////////// Management functions for building and traversing a Trie.
class Trie {
    private:
        trie_node* head;
        void clear_trie_rec(trie_node*);
    public:
        static int Get_Links_Position(char);
        static trie_node* Initialise_Node(char);
        static trie_node* Initialise_End_Node(char, int, int);
        static bool Base_In_Node(trie_node*, char);
        static trie_node* Add_Node(trie_node*, char);
        static trie_node* Add_End_Node(trie_node*, char, int, int);

        void Add_String(std::string, int, int);
        int Locate_Seq_At_Pos(std::string, int, int);
        int Locate_Seq_Subsection(std::string, int, int, int*);
        void Clear_Trie();
        Trie() {
            head = Trie::Initialise_Node('\0');
        }
};
#endif