//Dijkstra algo

#include <iostream>
using namespace std;

int main() {

    int graph[4][4] = {
        {0,4,1,0},
        {4,0,0,2},
        {1,0,0,5},
        {0,2,5,0}
    };

    int dist[4] = {0,999,999,999};

    bool visited[4] = {false};

    for(int i=0; i<4; i++) {

        int min = 999;
        int u;

        // Find minimum distance node
        for(int i=0; i<4; i++) {

            if(!visited[i] && min > dist[i]) {

                min = dist[i];
                u = i;
            }
        }

        // MARK NODE AS VISITED
        visited[u] = true;

        // Update distances
        for(int v=0; v<4; v++) {

            if(graph[u][v] != 0 &&
               !visited[v] &&
               dist[v] > graph[u][v] + dist[u]) {

                dist[v] = graph[u][v] + dist[u];
            }
        }
    }

    // Print result
    for(int i=0; i<4; i++) {

        cout << "Distance from 0 to "
             << i
             << " = "
             << dist[i]
             << endl;
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// CSP - Graph coloring

#include <iostream>
using namespace std;

int graph[4][4] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
};

int color[4];

// Check if color assignment is safe
bool isSafe(int node, int c) {

    for(int i=0; i<4; i++) {

        if(graph[node][i] == 1 &&
           color[i] == c) {

            return false;
        }
    }

    return true;
}

// Backtracking function
bool solve(int node, int cols) {

    // All nodes colored
    if(node == 4) {
        return true;
    }

    // Try all colors
    for(int c=1; c<=cols; c++) {

        if(isSafe(node, c)) {

            color[node] = c;

            // Recursive call
            if(solve(node + 1, cols)) {
                return true;
            }

            // Backtracking
            color[node] = 0;
        }
    }

    return false;
}

int main() {
    
    int cols=3;
    
    solve(0,cols);
    
    for(int i=0;i<4;i++){
        cout<<"Node "<<i<<" -> Color "<<color[i]<<endl;
    }
    
    return 0;   
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// CSP - N-Queen
#include <iostream>
using namespace std;

char board[4][4]={
    {'x','x','x','x'},
    {'x','x','x','x'},
    {'x','x','x','x'},
    {'x','x','x','x'}};

bool isSafe(int row, int col){
    //Upper column
    for(int i=0; i<row; i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    //Left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //Right diagonal
    for(int i=row, j=col; i>=0 && j<4; i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

bool solve(int row){
    if(row==4){
        return true;
    }
    
    for(int col=0; col<4; col++){
        if(isSafe(row,col)){
            board[row][col]='Q';
            
            if(solve(row+1)){
                return true;
            }
            
            board[row][col]='x';
        }
    }
    return false;
}

int main() {
    solve(0);
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<board[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//BFS
#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,1},
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,1,0,0,0}
};
    
    bool visited[5]={false};
    
    queue<int>Q;
    
    Q.push(0);
    visited[0]=true;

    while(Q.size()>0){
        int u= Q.front();
        Q.pop();
        
        cout<<u<<" ";
        
        for(int i=0;i<5;i++){
            if(graph[u][i]==1 && !visited[i]){
                visited[i]=true;
                Q.push(i);
            }
        }
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DFS
#include <iostream>

using namespace std;

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,1},
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,1,0,0,0}
};
    
bool visited[5]={false};
    
void dfs(int u){
    cout<<u<<" ";
    visited[u]=true;
        
    for(int i=0;i<5;i++){
        if(graph[u][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

int main() {
    
    dfs(0);
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Selection sort

#include <iostream>
using namespace std;

int main() {

    int arr[] = {4, 5, 1, 2, 3};
    int n = 5;

    // Selection Sort
    for(int i = 0; i < n; i++) {

        int minIndex = i;

        // Find smallest element
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Print sorted array
    cout << "Sorted Array: ";
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Prims algo
#include <iostream>
using namespace std;

int main() {

    int graph[4][4] = {
        {0,2,3,0},
        {2,0,1,4},
        {3,1,0,5},
        {0,4,5,0}
    };

    bool visited[4] = {false};

    visited[0] = true;

    int edges = 0;

    cout << "Edges in MST:\n";

    while(edges < 3) {

        int min = 999;
        int x, y;

        // Find minimum edge
        for(int i=0; i<4; i++) {

            if(visited[i]) {

                for(int j=0; j<4; j++) {

                    if(!visited[j] &&
                       graph[i][j] != 0 &&
                       graph[i][j] < min) {

                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y
             << " = " << graph[x][y]
             << endl;

        visited[y] = true;

        edges++;
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Kruskals algo
#include <iostream>
using namespace std;

int parent[4];

// Find parent
int find(int x) {

    while(parent[x] != x) {
        x = parent[x];
    }

    return x;
}

// Union of sets
void unite(int a, int b) {

    int pa = find(a);
    int pb = find(b);

    parent[pa] = pb;
}

int main() {

    // Edges: u, v, weight
    int edges[5][3] = {
        {1,2,1},
        {0,1,2},
        {0,2,3},
        {1,3,4},
        {2,3,5}
    };

    // Initialize parent array
    for(int i=0; i<4; i++) {
        parent[i] = i;
    }

    cout << "Edges in MST:\n";

    int count = 0;

    // Process edges
    for(int i=0; i<5; i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // Check cycle
        if(find(u) != find(v)) {

            cout << u << " - "
                 << v << " = "
                 << w << endl;

            unite(u,v);

            count++;
        }

        // MST complete
        if(count == 3) {
            break;
        }
    }

    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Chatbot
#include <iostream>
using namespace std;

// Function to greet user
void greet(string bot_name, string birth_year) {
    cout << "Hello! My name is " << bot_name << "." << endl;
    cout << "I was created in " << birth_year << "." << endl;
}

// Function to ask name
void remind_name() {
    string name;

    cout << "Please, remind me your name." << endl;
    cin >> name;

    cout << "What a great name you have, " << name << "!" << endl;
}

// Function to guess age
void guess_age() {
    int rem3, rem5, rem7, age;

    cout << "Let me guess your age." << endl;
    cout << "Enter remainders of dividing your age by 3, 5 and 7." << endl;

    cin >> rem3;
    cin >> rem5;
    cin >> rem7;

    age = (rem3 * 70 + rem5 * 21 + rem7 * 15) % 105;

    cout << "Your age is " << age
         << "; that's a good time to start programming!" << endl;
}

// Function to count numbers
void count() {
    int num;

    cout << "Now I will prove to you that I can count to any number you want." << endl;

    cin >> num;

    for(int i = 0; i <= num; i++) {
        cout << i << " !" << endl;
    }
}

// Function for quiz
void test() {
    int guess;

    cout << "Let's test your programming knowledge." << endl;

    cout << "Why do we use methods?" << endl;
    cout << "1. To repeat a statement multiple times." << endl;
    cout << "2. To decompose a program into several small subroutines." << endl;
    cout << "3. To determine the execution time of a program." << endl;
    cout << "4. To interrupt the execution of a program." << endl;

    cin >> guess;

    while(guess != 2) {
        cout << "Please, try again." << endl;
        cin >> guess;
    }

    cout << "Completed, have a nice day!" << endl;
}

// Ending function
void end() {
    cout << "Congratulations, have a nice day!" << endl;
}

int main() {

    greet("Sbot", "2021");

    remind_name();

    guess_age();

    count();

    test();

    end();

    return 0;
}

