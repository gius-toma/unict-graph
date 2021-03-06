#pragma once

#include "graph_vertex.hpp"

template <typename T>
class Graph_List {
    List<Graph_Vertex<T>> m_vertices;

    std::size_t n_vertex;
    bool is_oriented;

public:
    Graph_List(bool is_oriented=true) : n_vertex(0), is_oriented(is_oriented) {}

    void add_vertex(T const& vertex) {        
        Graph_Vertex<T> add(vertex);
        m_vertices.insert(add);
        ++n_vertex;
    }

    void add_edge(T const& data0, T const& data1) {
        Node<Graph_Vertex<T>>* node0 = search(data0);
        Node<Graph_Vertex<T>>* node1 = search(data1);

        if (node0 && node1) {
            node0->get_data().insert(data1);
            if (!this->is_oriented) {
                node1->get_data().insert(data0);
            }
        }
    }

    Node<Graph_Vertex<T>>* search(T const& data) {
        if(this->n_vertex == 0)
            return nullptr;

        Node<Graph_Vertex<T>>* ptr = this->m_vertices.get_head();
        while (ptr) {
            if (data == ptr->get_data().get_head()->get_data())
                return ptr;
            ptr = ptr->get_next();
        } return nullptr;
    }

    friend std::ostream& operator<< (std::ostream& out, Graph_List<T>& gl) {
        out << gl.m_vertices;
        return out;
    }
};