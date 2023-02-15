struct Penguins{
    int x;
    int y;
    int MoveLable;
};

struct Players{
    char name[20];
    int score;
};

enum PHASE {Generation, Placement, Movement,Choose};
enum PHASE phase;