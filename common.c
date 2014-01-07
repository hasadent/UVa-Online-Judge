// simple queue
int _Q[MAX];
int _QF = 0, _QR = 0;
#define Q_RESET()       _QF = _QR = 0;
#define Q_ENQUEUE(v0)   _Q[_QR++] = (v0);
#define Q_DEQUEUE()     _Q[_QF++]
#define Q_IS_EMPTY()    (_QF == _QR)

// simple circular queue
#define Q_SIZE      ??
int _Q[Q_SIZE];
int _QF = 0, _QR = 0;
#define Q_RESET()       _QF = _QR = 0;
#define Q_ENQUEUE(v0)   { _Q[_QR] = (v0); _QR = (_QR + 1) % Q_SIZE; }
#define Q_DEQUEUE(v0)   { v0 = _Q[_QF]; _QF = (_QF + 1 ) % Q_SIZE; }
#define Q_IS_EMPTY()    (_QF == _QR)



// simple stack
#define ST_SIZE          ??
int _S[ST_SIZE];
int _ST = 0;
#define ST_RESET()      _ST = 0;
#define ST_PUSH(v0)     _S[_ST++] = (v0);
#define ST_POP(v0)      v0 = _S[--_ST]
#define ST_TOP()        _S[_ST-1]
#define ST_IS_EMPTY()   (_ST == 0)



#define VISITED_SIZE   ??
int _visited_key = 1;
int _visited[VISITED_SIZE];
#define INIT_VISITED(_i_) for (_i_ = 0; _i_ < VISITED_SIZE; _i_+=1) { _visited[_i_] = 0; }
#define RESET_VISITED()   _visited_key ++;
#define SET_VISITED(v0)   _visited[(v0)] = _visited_key;
#define IS_VISITED(v0)    (_visited[(v0)] == _visited_key)
