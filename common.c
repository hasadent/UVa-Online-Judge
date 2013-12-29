// simple queue
int _Q[MAX];
int _QF = 0, _QR = 0;
#define Q_RESET()       _QF = _QR = 0;
#define Q_ENQUEUE(v0)   _Q[_QR++] = (v0); printf("ENQ %d\n", (v0));
#define Q_DEQUEUE()     _t = _Q[_QF++]; printf("    DEQ %d\n", _t);
#define Q_IS_EMPTY()    (_QF == _QR)

// simple stack
int _S[MAX];
int _ST = 0;
#define ST_RESET()      _ST = 0;
#define ST_PUSH(v0)     _S[_ST++] = (v0); printf("PUSH %d\n", (v0));
#define ST_POP()        _t = _S[--_ST]; printf("    POP %d\n", _t);
#define ST_TOP()        _S[_ST-1]
#define ST_IS_EMPTY()   (_ST == 0)
