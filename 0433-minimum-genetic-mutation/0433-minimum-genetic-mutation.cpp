class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
         unordered_set<string> bankSet(bank.begin(), bank.end());


        //visited set
        unordered_set<string>visited;

        //queue for BFS
        queue<string> q;

        //Begin BFS with startGene
        q.push(startGene);
        visited.insert(startGene);
        
        int level = 0;

        while(!q.empty()){
            int n = q.size() ; //size of level

            while(n--){ //traverse in each level
                string curr = q.front();
                q.pop() ;

                if(curr == endGene){
                    return level ; //reached target endGene
                }

                for(char ch : "ACGT"){
                    for(int i=0 ; i<curr.length() ; i++){
                        string neigh = curr ;
                        neigh[i] = ch ;//first try with 'A' ,then 'C' then 'G' ,then 'T'


                        //check if it is visited and present in bank
                        if(visited.find(neigh) == visited.end() &&
                        bankSet.find(neigh) != bankSet.end()){
                            //if both conditions true
                            visited.insert(neigh) ; 
                            q.push(neigh) ;
                        }
                    }
                }
            }

            level++ ; 
        }

        //if impossible to find 
        return -1 ;
    }
};