#include<iostream>
#include<list>
#include<vector>
#include<iterator>
using namespace std;
#ifndef FLIGHT_H
#define FLIGHT_H

class Edge{
    public:
     int DestinationVertexID;
     int weight;
     Edge(){}
     Edge(int destID,int w){
        DestinationVertexID=destID;
        weight=w;
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
        cout << it -> getDestinationVertexID() << "(" << it -> getWeight() << ") --> ";
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
  public:
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
  void addEdgeByID(int fromVertex, int toVertex, int weight) {
    bool check1 = checkIfVertexExistByID(fromVertex);
    bool check2 = checkIfVertexExistByID(toVertex);
    bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);
    if ((check1 && check2 == true)) {
      if (check3 == true) {
        cout << "Edge between " << getVertexByID(fromVertex).getStateName() << "(" << fromVertex << ") and " << getVertexByID(toVertex).getStateName() << "(" << toVertex << ") Already Exist" << endl;
      } else {
        for (int i = 0; i < vertices.size(); i++) {
          if (vertices.at(i).getStateID() == fromVertex) {
            Edge e(toVertex, weight);
            vertices.at(i).edgelist.push_back(e);
          } else if (vertices.at(i).getStateID() == toVertex) {
            Edge e(toVertex, weight);
            vertices.at(i).edgelist.push_back(e);
          }
        }
        cout << "Edge between " << fromVertex << " and " << toVertex << " added Successfully" << endl;
      }
    } else {
      cout << "Invalid Vertex ID entered.";
    }
  }
  void updateEdgeByID(int fromVertex, int toVertex, int newWeight) {
    bool check = checkIfEdgeExistByID(fromVertex, toVertex);
    if (check == true) {
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateID() == fromVertex) {
          for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
            if (it -> getDestinationVertexID() == toVertex) {
              it -> setWeight(newWeight);
              break;
            }
          }
        } else if (vertices.at(i).getStateID() == toVertex) {
          for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
            if (it -> getDestinationVertexID() == fromVertex) {
              it -> setWeight(newWeight);
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
              break;
            }
          }
        }
        if (vertices.at(i).getStateID() == toVertex) {
          for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++) {
            if (it -> getDestinationVertexID() == fromVertex) {
              vertices.at(i).edgelist.erase(it);
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
          cout << it -> getDestinationVertexID() << "(" << it -> getWeight() << ") --> ";
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
};
/*int main() {
  Graph g;
  string sname;
  int id1, id2, w;
  int option;
  bool check;
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
      g.addEdgeByID(id1, id2, w);
      break;
    case 5:
      cout << "Update Edge Operation -" << endl;
      cout << "Enter ID of Source Vertex(State): ";
      cin >> id1;
      cout << "Enter ID of Destination Vertex(State): ";
      cin >> id2;
      cout << "Enter UPDATED Weight of Edge: ";
      cin >> w;
      g.updateEdgeByID(id1, id2, w);
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
    default:
      cout << "Enter Proper Option number " << endl;
    }
    cout << endl;
  } while (option != 0);
  return 0;
}*/
#endif
