#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <stack>
#include <queue>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

class Edge{
    public:
     int DestinationVertexID;
     int weight;
     int cost;

     int getCost()
     {
       return this->cost;
     }

     void setCost(int cost)
     {
       this->cost = cost;
     }

     Edge(){}
     Edge(int destID,int w,int cst){
        DestinationVertexID=destID;
        weight=w;
        cost=cst;
     }

    void setEdgeValues(int destVID, int w) {
        DestinationVertexID = destVID;
        weight = w;
    }
    void setWeight(int w) {
        weight = w;
    }
    int getDestinationVertexID() {
        return DestinationVertexID;
    }
    int getWeight() {
        return weight;
    }
};
class Vertex{
    public:
    int state_id;
    string state_name;
    list<Edge> edgelist;
    Vertex(){
        state_id=0;
        state_name="";
    }
    Vertex(int id,string name){
        state_id=id;
        state_name=name;
    }

    int getStateID() {
        return state_id;
    }
    string getStateName() {
        return state_name;
    }
    void setID(int id) {
        state_id = id;
    }
    void setStateName(string sname) {
        state_name = sname;
    }
    list < Edge > getedgelist() {
        return edgelist;
    }

    void printedgelist() {
        cout << "[";
        for (auto it = edgelist.begin(); it != edgelist.end(); it++) {
        cout << it -> getDestinationVertexID() << "(" << it -> getWeight() << ", "<<it->getCost()<< ") --> ";
        }
        cout << "]";
        cout << endl;
    }
    void updateVertexName(string sname) {
        state_name = sname;
        cout << "Vertex Name Updated Successfully";
    }
};

class Graph {
  vector < Vertex > vertices;
  // private:
  vector<int> predecessorW,predecessorC;

  public:
  Graph() {
        predecessorW.resize(vertices.size(), -1); 
        predecessorC.resize(vertices.size(), -1); 
  }
    bool checkIfVertexExistByID(int vid) {
      bool flag = false;
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateID() == vid) {
          return true;
        }
      }
      return flag;
    }
  void addVertex(Vertex newVertex) {
    bool check = checkIfVertexExistByID(newVertex.getStateID());
    if (check == true) {
      cout << "Vertex with this ID already exist" << endl;
    } else {
      vertices.push_back(newVertex);
      cout << "New Vertex Added Successfully" << endl;
    }
  }
  Vertex getVertexByID(int vid) {
    Vertex temp;
    for (int i = 0; i < vertices.size(); i++) {
      temp = vertices.at(i);
      if (temp.getStateID() == vid) {
        return temp;
      }
    }
    return temp;
  }
  bool checkIfEdgeExistByID(int fromVertex, int toVertex) {
    Vertex v = getVertexByID(fromVertex);
    list < Edge > e;
    e = v.getedgelist();
    bool flag = false;
    for (auto it = e.begin(); it != e.end(); it++) {
      if (it -> getDestinationVertexID() == toVertex) {
        flag = true;
        return flag;
        break;
      }
    }
    return flag;
  }
  void updateVertex(int oldVID, string vname) {
    bool check = checkIfVertexExistByID(oldVID);
    if (check == true) {
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateID() == oldVID) {
          vertices.at(i).setStateName(vname);
          break;
        }
      }
      cout << "Vertex(State) Updated Successfully " << endl;
    }
  }
  void addEdgeByID(int fromVertex, int toVertex, int weight,int cst) {
    bool check1 = checkIfVertexExistByID(fromVertex);
    bool check2 = checkIfVertexExistByID(toVertex);
    bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);
    if ((check1 && check2 == true)) {
      if (check3 == true) {
        cout << "Edge between " << getVertexByID(fromVertex).getStateName() << "(" << fromVertex << ") and " << getVertexByID(toVertex).getStateName() << "(" << toVertex << ") Already Exist" << endl;
      } else {
        for (int i = 0; i < vertices.size(); i++) {
          if (vertices.at(i).getStateID() == fromVertex) {
            Edge e(toVertex, weight,cst);
            //edgelist.push_back(e); 
            //vertices.at(i).addEdgeToedgelist(toVertex,weight);
            vertices.at(i).edgelist.push_back(e);
          } else if (vertices.at(i).getStateID() == toVertex) {
            Edge e(fromVertex, weight,cst);
            //edgelist.push_back(e); 
            //vertices.at(i).addEdgeToedgelist(fromVertex,weight);
            vertices.at(i).edgelist.push_back(e);
          }
        }
        cout << "Edge between " << fromVertex << " and " << toVertex << " added Successfully" << endl;
      }
    } else {
      cout << "Invalid Vertex ID entered.";
    }
  }
  void updateEdgeByID(int fromVertex, int toVertex, int newWeight,int newCst) {
    bool check = checkIfEdgeExistByID(fromVertex, toVertex);
    if (check == true) {
    cout << "Updating edge from " << fromVertex << " to " << toVertex << " with weight " << newWeight << endl;
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateID() == fromVertex) {
          for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
            if (it -> getDestinationVertexID() == toVertex) {
              cout << "Edge Weight Updated Successfully " << endl;
              it -> setWeight(newWeight);
              it->setCost(newCst);
              break;
            }
          }
        } else if (vertices.at(i).getStateID() == toVertex) {
          for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
            if (it -> getDestinationVertexID() == fromVertex) {
              cout << "Edge Weight Updated Successfully " << endl;
              it -> setWeight(newWeight);
              it->setCost(newCst);
              break;
            }
          }
        }
      }
      cout << "Edge Weight Updated Successfully " << endl;
    } else {
      cout << "Edge between " << getVertexByID(fromVertex).getStateName() << "(" << fromVertex << ") and " << getVertexByID(toVertex).getStateName() << "(" << toVertex << ") DOES NOT Exist" << endl;
    }
  }
  void deleteEdgeByID(int fromVertex, int toVertex) {
    bool check = checkIfEdgeExistByID(fromVertex, toVertex);
    if (check == true) {
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateID() == fromVertex) {
          for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
            if (it -> getDestinationVertexID() == toVertex) {
              vertices.at(i).edgelist.erase(it);
              //cout<<"First erase"<<endl;
              break;
            }
          }
        }
        if (vertices.at(i).getStateID() == toVertex) {
          for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
            if (it -> getDestinationVertexID() == fromVertex) {
              vertices.at(i).edgelist.erase(it);
              //cout<<"second erase"<<endl;
              break;
            }
          }
        }
      }
      cout << "Edge Between " << fromVertex << " and " << toVertex << " Deleted Successfully." << endl;
    }
  }
  void deleteVertexByID(int vid) {
    int vIndex = 0;
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices.at(i).getStateID() == vid) {
        vIndex = i;
      }
    }
    for (int i = 0; i < vertices.size(); i++) {
      for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
        if (it -> getDestinationVertexID() == vid) {
          vertices.at(i).edgelist.erase(it);
          break;
        }
      }
    }
    vertices.erase(vertices.begin() + vIndex);
    cout << "Vertex Deleted Successfully" << endl;
  }
  void getAllNeigborsByID(int vid) {
    cout << getVertexByID(vid).getStateName() << " (" << getVertexByID(vid).getStateID() << ") --> ";
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices.at(i).getStateID() == vid) {
        cout << "[";
        for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
          cout << it -> getDestinationVertexID() << "(" << it -> getWeight() <<", "<< it->getCost()<< ") --> ";
        }
        cout << "]";
      }
    }
  }
  void printGraph() {
    for (int i = 0; i < vertices.size(); i++) {
      Vertex temp;
      temp = vertices.at(i);
      cout << temp.getStateName() << " (" << temp.getStateID() << ") --> ";
      temp.printedgelist();
    }
  }
  Vertex get(int Vid){
    Vertex temp;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateID() == Vid) {
          temp=vertices.at(i);
        }
      }
      return temp;
  }
  void BFSPrint(int Vid) {
    if (checkIfVertexExistByID(Vid)) {
        Vertex temp = get(Vid);
        vector<bool> visited(vertices.size(), false);
        queue<int> q;
        q.push(temp.getStateID());
        visited[Vid] = true;
        while (!q.empty()) {
            Vid = q.front();
            cout << Vid << " ";
            q.pop();

            for (auto adj : temp.getedgelist()) {
                int adjID = adj.getDestinationVertexID();
                if (!visited[adjID]) {
                    q.push(adjID);
                    visited[adjID] = true;
                }
            }
        }
        cout << endl;
    }
}

   // Dijkstra's Algorithm
    vector<int> dijkstraWeight(int source, int destination) {
        vector<int> dist(vertices.size(), INT_MAX);
        dist[source] = 0;
        predecessorW.resize(vertices.size(), -1);
        set<pair<int, int>> pq;
        pq.insert({0, source});

        while (!pq.empty()) {
            int u = pq.begin()->second;
            pq.erase(pq.begin());

            for (const Edge& e : vertices[u].edgelist) {
                int v = e.DestinationVertexID;
                int weight = e.weight;
                // Update distance if a shorter path is found
                if (dist[v] > dist[u] + weight) {
                    pq.erase({dist[v], v});
                    dist[v] = dist[u] + weight;
                    pq.insert({dist[v], v});
                    predecessorW[v]=u;
                }
            }

            // If the destination is reached, break out of the loop
            if (u == destination) {
                break;
            }
        }
        return dist;
    }


    void printShortestPathWeight(int source, int destination) {
        if (predecessorW[destination] == -1) {
            cout << "No path exists from " << source << " to " << destination << endl;
            return;
        }

        vector<int> path;
        for (int v = destination; v != source; v = predecessorW[v]) {
            path.push_back(v);
        }
        path.push_back(source);

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
    }
   
   vector<int> dijkstraCost(int source, int destination) {
        vector<int> dist(vertices.size(), INT_MAX);
        dist[source] = 0;
        predecessorC.resize(vertices.size(), -1);
        set<pair<int, int>> pq;
        pq.insert({0, source});

        while (!pq.empty()) {
            int u = pq.begin()->second;
            pq.erase(pq.begin());

            for (const Edge& e : vertices[u].edgelist) {
                int v = e.DestinationVertexID;
                int COST = e.cost;
                // Update distance if a shorter path is found
                if (dist[v] > dist[u] + COST) {
                    pq.erase({dist[v], v});
                    dist[v] = dist[u] + COST;
                    pq.insert({dist[v], v});
                    predecessorC[v]=u;
                }
            }

            // If the destination is reached, break out of the loop
            if (u == destination) {
                break;
            }
        }
        return dist;
    }

    
    void printShortestPathCost(int source, int destination) {
        if (predecessorC[destination] == -1) {
            cout << "No path exists from " << source << " to " << destination << endl;
            return;
        }

        vector<int> path;
        for (int v = destination; v != source; v = predecessorC[v]) {
            path.push_back(v);
        }
        path.push_back(source);

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
    }

};
int main() {
  Graph g;
    string sname;
    vector<int> distances;
    int id1, id2, w, source, destination;
    int option;
    bool check;
    int cst;
    vector<int> shortestDistances ;
  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Add Vertex" << endl;
    cout << "2. Update Vertex" << endl;
    cout << "3. Delete Vertex" << endl;
    cout << "4. Add Edge" << endl;
    cout << "5. Update Edge" << endl;
    cout << "6. Delete Edge" << endl;
    cout << "7. Check if 2 Vertices are Neigbors" << endl;
    cout << "8. Print All Neigbors of a Vertex" << endl;
    cout << "9. Print Graph" << endl;
    cout << "10. Clear Screen" << endl;
    cout << "11. BFS" << endl;
    cout << "12. Shortest Path (BY TIME)" << endl;
    cout << "13. Shortest Path (BY TIME)" << endl;
    cout << "0. Exit Program" << endl;
    cin >> option;
    Vertex v1;
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Add Vertex Operation -" << endl;
      cout << "Enter State ID :";
      cin >> id1;
      cout << "Enter State Name :";
      cin >> sname;
      v1.setID(id1);
      v1.setStateName(sname);
      g.addVertex(v1);
      break;
    case 2:
      cout << "Update Vertex Operation -" << endl;
      cout << "Enter State ID of Vertex(State) to update :";
      cin >> id1;
      cout << "Enter State Name :";
      cin >> sname;
      g.updateVertex(id1, sname);
      break;
    case 3:
      cout << "Delete Vertex Operation -" << endl;
      cout << "Enter ID of Vertex(State) to Delete : ";
      cin >> id1;
      g.deleteVertexByID(id1);
      break;
    case 4:
      cout << "Add Edge Operation -" << endl;
      cout << "Enter ID of Source Vertex(State): ";
      cin >> id1;
      cout << "Enter ID of Destination Vertex(State): ";
      cin >> id2;
      cout << "Enter Weight of Edge: ";
      cin >> w;
      cout << "Enter cost of Edge: ";
      cin >> cst;
      g.addEdgeByID(id1, id2, w,cst);
      break;
    case 5:
      cout << "Update Edge Operation -" << endl;
      cout << "Enter ID of Source Vertex(State): ";
      cin >> id1;
      cout << "Enter ID of Destination Vertex(State): ";
      cin >> id2;
      cout << "Enter UPDATED Weight of Edge: ";
      cin >> w;
      cout << "Enter UPDATED Cost of Edge: ";
      cin >> cst;
      g.updateEdgeByID(id1, id2, w,cst);
      break;
    case 6:
      cout << "Delete Edge Operation -" << endl;
      cout << "Enter ID of Source Vertex(State): ";
      cin >> id1;
      cout << "Enter ID of Destination Vertex(State): ";
      cin >> id2;
      g.deleteEdgeByID(id1, id2);
      break;
    case 7:
      cout << "Check if 2 Vertices are Neigbors -" << endl;
      cout << "Enter ID of Source Vertex(State): ";
      cin >> id1;
      cout << "Enter ID of Destination Vertex(State): ";
      cin >> id2;
      check = g.checkIfEdgeExistByID(id1, id2);
      if (check == true) {
        cout << "Vertices are Neigbors (Edge exist)";
      } else {
        cout << "Vertices are NOT Neigbors (Edge does NOT exist)";
      }
      break;
    case 8:
      cout << "Print All Neigbors of a Vertex -" << endl;
      cout << "Enter ID of Vertex(State) to fetch all Neigbors : ";
      cin >> id1;
      g.getAllNeigborsByID(id1);
      break;
    case 9:
      cout << "Print Graph Operation -" << endl;
      g.printGraph();
      break;
    case 11:
      cout << "BFS Print" << endl;
      g.BFSPrint(1);
      break;
    case 12:
        cout << "Dijkstra's Algorithm" << endl;
        cout << "Enter source vertex: ";
        cin >> source;
        cout << "Enter destination vertex: ";
        cin >> destination;

        shortestDistances = g.dijkstraWeight(source, destination);

        // Print the shortest distance to the destination vertex
        cout << "Shortest Distance from " << source << " to " << destination << ": " << shortestDistances[destination] << endl;

        // Print the shortest path
        g.printShortestPathWeight(source, destination);
        break;
      case 13:
        cout << "Dijkstra's Algorithm" << endl;
        cout << "Enter source vertex: ";
        cin >> source;
        cout << "Enter destination vertex: ";
        cin >> destination;

        shortestDistances = g.dijkstraCost(source, destination);

        // Print the shortest distance to the destination vertex
        cout << "Shortest Distance from " << source << " to " << destination << ": " << shortestDistances[destination] << endl;

        // Print the shortest path
        g.printShortestPathCost(source, destination);
        break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
    cout << endl;
  } while (option != 0);
  return 0;
}
