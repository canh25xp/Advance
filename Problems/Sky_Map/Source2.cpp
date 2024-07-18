#include <iostream>
using namespace std;

#define DEFAULT_TEST_CASE 10

const int MAX_SIZE = 25;

// Direction : left, right, up, down
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};
int checked[MAX_SIZE][MAX_SIZE] = {};

struct Point
{
    Point();
    Point(int _x, int _y);
    int x,y;
};

void DFS(Point p);

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "eval_input.txt", "r", stdin);

	int TEST_CASE = DEFAULT_TEST_CASE;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
        int size = 0;
        cin >> size;

        int matrix[MAX_SIZE][MAX_SIZE] = {};

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int constellars = 0;
        int max = 0;

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (matrix[i][j] == 1 && checked[i][j] != 1){
                }
            }
        }

		cout<< constellars << " " << max << endl;
	}

	return 0;
}

void DFS(Point p){
    for (int k = 0; k < 4; k++){

    }
}

Point::Point(){
    this->x = 0;
    this->y = 0;
}

Point::Point(int _x, int _y){
    this->x = _x;
    this->y = _y;
}