#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    int id;
    bool isEnd = false;
    bool visited = false;
    vector<int> next;
    Node(int _id) : id(_id){};
    Node();
};
enum
{
    failed,
    success,
    startPoint = 2
};

void initialMaze(vector<Node *> &all, vector<int> end);
bool dfs(Node *cur, vector<Node *> &all, vector<int> &path);
void CountNShowPath(vector<int> &path);

using namespace std;

int main()
{
    vector<int> end;
    //
    end.push_back(17);
    vector<Node *> all = {nullptr};
    initialMaze(all, {17});
    vector<int> path;
    if (!dfs(all[startPoint], all, path))
    {
        cerr << "Cant go out of the maze.\n";
        system("pause");
        return -1;
    };
    // bfs(all);
    system("pause");
    return 0;
}

void initialMaze(vector<Node *> &all, vector<int> end)
{

    for (int i = 1; i < 18; ++i)
    {
        Node *t = new Node(i);
        all.push_back(t);
    }
    for (int i : end)
        all[i]->isEnd = true;

    all[1]->next.assign({3});
    all[2]->next.assign({3});
    all[3]->next.assign({1, 2, 4, 6, 7, 8});
    all[4]->next.assign({3, 5});
    all[5]->next.assign({4});
    all[6]->next.assign({3});
    all[7]->next.assign({3, 8, 11});
    all[8]->next.assign({3, 7, 9, 12});
    all[9]->next.assign({8, 13});
    all[10]->next.assign({14});
    all[11]->next.assign({7, 12});
    all[12]->next.assign({8, 11, 13});
    all[13]->next.assign({9, 12, 14, 16});
    all[14]->next.assign({10, 13});
    all[15]->next.assign({16});
    all[16]->next.assign({13, 15, 17});
    all[17]->next.assign({16});
}

bool dfs(Node *cur, vector<Node *> &all, vector<int> &path)
{
    path.push_back(cur->id);
    if (cur->isEnd)
    {
        CountNShowPath(path);
        return true;
    }
    cur->visited = true;
    for (int i : cur->next)
        if (!all[i]->visited && dfs(all[i], all, path))
            return true;
    path.pop_back();
    return false;
}

void bfs(vector<Node *> &all)
{
    vector<int> path;
    queue<Node *> q;
    q.push(all[startPoint]);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        path.push_back(cur->id);
        cur->visited = true;
        if (cur->isEnd)
            break;
        for (int i : cur->next)
            if (!all[i]->visited)
                q.push(all[i]);
    }
    //CountNShowPath(path);
}

void CountNShowPath(vector<int> &path)
{
    cout << "length : " << path.size() - 1 << "\npath : ";
    for (int i : path)
        cout << i << "  ";
    cout << "\n\n";
}