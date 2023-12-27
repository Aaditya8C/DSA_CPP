 while (!sortedVertices.empty())
        {
            int u = sortedVertices.front();
            sortedVertices.pop();
            for (auto elem : adj[u])
            {
                if(color[elem] == "white"){
                    color[elem] = "gray";
                    pd[elem] = u;
                    sortedVertices.push(elem);
                }
            }
            cout << u;
            color[u] = "black";
        }