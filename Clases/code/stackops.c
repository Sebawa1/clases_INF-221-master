typedef item...;
item A[...];
static int top = 0;

void push(item A[], item x) { A[top++] = x; }

item pop(item A[]) { return A[--top]; }
