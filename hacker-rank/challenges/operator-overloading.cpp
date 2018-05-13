
class Matrix{
public:
    vector< vector<int> > a;
    
    Matrix operator + (Matrix const & right){
        Matrix resp;
        int n = a.size();
        int m = a[0].size();
        int i, j, num;
        
        for(i = 0; i < n ; i++) {
         vector<int> tempRow;
            
         for(j = 0; j < m ; j++) {
            num = a[i][j] + right.a[i][j];
            tempRow.push_back(num);
         }
         resp.a.push_back(tempRow);
        }
        
        return resp;
    }
    
};
