#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

struct node
{
    char title[30];
    int chapter_cnt;
    int sb_cnt;
    struct node *child[30];
} *root;

class Tree
{
public:
    void create();
    void display(node *r1);

    Tree()
    {
        root = NULL;
    }
};

void Tree::create()
{
    int tbooks, tchapters, i, j, k;
    root = new node();
    cout << "Enter Name of the Book : ";
    cin >> root->title;
    cout << "Enter the no. of Chapters in the Book: ";
    cin >> tchapters;
    root->chapter_cnt = tchapters;

    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "\nEnter Chapter no. " << i + 1 << " Name: ";
        cin >> root->child[i]->title;
        cout << "Enter no. of Sections in Chapter " << root->child[i]->title << ": ";
        cin >> root->child[i]->chapter_cnt;

        for (j = 0; j < root->child[i]->chapter_cnt; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "\nEnter Section " << j + 1 << " name: ";
            cin >> root->child[i]->child[j]->title;
            cout << "Enter no. of subsections in Section " << root->child[i]->child[j]->title << ": ";
            cin >> root->child[i]->child[j]->sb_cnt;

            for (k = 0; k < root->child[i]->child[j]->sb_cnt; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "\nEnter Subsection " << k + 1 << " name: ";
                cin >> root->child[i]->child[j]->child[k]->title;
            }
        }
    }
}

void Tree::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book-----\n";
        cout << "BOOK TITLE: " << r1->title;
        cout << "\n*** CHAPTERS ***" << endl;
        tchapters = r1->chapter_cnt;

        for (i = 0; i < tchapters; i++)
        {
            cout << "\n"
                 << i + 1 << ". " << r1->child[i]->title;

            for (j = 0; j < r1->child[i]->chapter_cnt; j++)
            {
                cout << "\n\t" << i + 1 << "." << j + 1 << ". " << r1->child[i]->child[j]->title;

                for (k = 0; k < r1->child[i]->child[j]->sb_cnt; k++)
                {
                    cout << "\n\t\t" << i + 1 << "." << j + 1 << "." << k + 1 << ". " << r1->child[i]->child[j]->child[k]->title;
                }
            }
        }
    }
}

int main()
{
    int choice;
    Tree tree;
    
    while (1)
    {
        cout << "\n-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.create();
            break;
        case 2:
            tree.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "\nWrong Choice!" << endl;
        }
    }
}
