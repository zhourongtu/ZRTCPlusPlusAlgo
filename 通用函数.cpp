class usualFunc{
public:
    void printTwoDimension(std::vector<std::vector<int>> &arr){
        using std::cout;
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[i].size(); j++){
                if(j!=0)cout << " ";
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
};