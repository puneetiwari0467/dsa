#define pb push_back
class Solution {
	public:
		//map< int ,vector< int > > graph ;
		  
		struct vertex {
			int index ;  // time_stamp 
			int lowlink ; // The earliest point that can be reached by a non-father node
		};
		int time_stamp = 1 ;
        vector< vertex > check ;
		vector< vector<int> > ans ; 
		void dfs( vector<vector<int>>&graph,int v , int parent ) {

			check[v].index = time_stamp ; 
			check[v].lowlink = time_stamp ;
			time_stamp ++ ;

			for( auto &w : graph[v] ){
				if ( w == parent ) continue ; 
				if ( check[w].index == 0 ){ // not visited
					dfs( graph,w , v ) ; 
					// calc The earliest point that can be reached by a non-father node
					check[v].lowlink = min( check[v].lowlink , check[w].lowlink ) ; 
					if ( check[w].lowlink > check[v].index ) // this must be a bridge 
						ans.pb( {v,w } ) ; 
				}  else {
					check[v].lowlink = min( check[v].lowlink , check[w].index ) ; 
				}
			}

		}
		vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edge) {
			check.resize( n+1 ) ; 
            vector<vector<int>>g(n+1);
			// construct graph 
			for( int i=0;i<edge.size();i++) {
                int x=edge[i][0];
                int y=edge[i][1];
                g[x].pb(y);
                g[y].pb(x);
			}
			for( int i=0 ; i<=n ; i++ ) 
				if ( check[i].index == 0 ) // not visited 
					dfs( g,i , -1 ) ; 
			return ans ; 
		}
	};