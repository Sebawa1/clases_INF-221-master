#!/usr/bin/python3

from random import randint

def makeset(V):
    global rank, parent
    rank = [0 for i in range(V)]
    parent = [i for i in range(V)]

def find(u):
    while u != parent[u]:
	u = parent[u]
    return u;

def union(u, v):
    u = find(u)
    v = find(v)
    if u != v:
	if rank[u] > rank[v]:
	    parent[v] = u
	else:
	    parent[u] = v
	    if rank[u] == rank[v]:
		rank[u] += 1

def showset(V):
    for x in range(V):
	print("(", x + 1, ", ", parent[x] + 1, ")")

V = 20
makeset(V)
for x in range(V):
    u = randint(0, V - 1)
    v = randint(0, V - 1)
    if(u != v):
	union(u, v)
showset(V)
