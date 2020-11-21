//algorithm:search
//输入：key
//输出：如果有，返回找到的内存空间中的值，没有返回NULL
searchKeykey
if !ready 
    return nullptr;
if root = NULL
    return nullptr;
else
    InNode *now<-root;
    while now->isleave = false do
        int pos <- upper_boundnow->keys.begin, now->keys.end, key - now->keys.begin;
        now<-now->childs[pos]; 
    end
    int pos <- lower_boundnow->keys.begin, now->keys.end, key - now->keys.begin; 
    if pos = now->keys.size || now->keys[pos] != key
        return;
    return now->stores[pos].data;



//algorithm:insert
//输入：key,data
//输出：无
insert(Key key, Store store)
    if !ready
        return;
    if root = nullptr
        root <- new InNode;
        root->isleave <- true;
        root->keys.push_back(key);
        root->stores.push_back(store);
    else
        InNode *now <- root;
        InNode *last <- NULL;
        while now->isleave != true do
            last <- now;
            int pos <- 0;
            pos <- upper_boundnow->keys.begin, now->keys.end, key - now->keys.begin;
            now <- now->childs[pos];
        end
        if now->keys.size < LeaveNum
            int pos <- 0;
            pos <- upper_boundnow->keys.begin, now->keys.end, key - now->keys.begin;
            now->keys.insertnow->keys.begin + pos, key;
            now->stores.insertnow->stores.begin + pos, store;
        else
            vector<Key> tempKeysnow->keys;
            vector<Store> tempStoresnow->stores;
            int pos;
            pos <- upper_boundnow->keys.begin, now->keys.end, key - now->keys.begin;
            tempKeys.inserttempKeys.begin + pos, key;
            tempStores.inserttempStores.begin + pos, store;
            InNode *newNode <- new InNode;
            newNode->isleave <- true;
            swapnow->next, newNode->next;
            now->keys.resizeLeaveNum / 2 + 1; 
            now->stores.resizeLeaveNum / 2 + 1;
            for int i <- 0; i <= LeaveNum / 2; i++
                now->keys[i] <- tempKeys[i];
                now->stores[i] <- tempStores[i];
            end
            for int i <- LeaveNum / 2 + 1; i < tempKeys.size; i++
                newNode->keys.push_back(tempKeys[i]);
                newNode->stores.push_back(tempStores[i]);
            end
            if now = root
                InNode *newRoot <- new InNode;
                newRoot->keys.push_bac(knewNode->keys[0]);
                newRoot->childs.push_back(now);
                newRoot->childs.push_back(newNode);
                root <- newRoot;
            
            else        
                insertInNodenewNode->keys[0], last, newNode;
    end       
insertInNodeKey(key, InNode *&last, InNode *&newNode)

    if last->keys.size < MiddleNum - 1 
        int pos <- upper_boundlast->keys.begin, last->keys.end, key - last->keys.begin;
        last->keys.insertlast->keys.begin + pos, key;
        last->childs.insertlast->childs.begin + pos + 1, newNode;
    end
    else 
        vector<int> tempKeyslast->keys;
        vector<InNode *> tempchildslast->childs;
        int pos <- upper_boundlast->keys.begin, last->keys.end, key - last->keys.begin;
        tempKeys.inserttempKeys.begin + pos, key; 
        tempchilds.inserttempchilds.begin + pos + 1, newNode;
        int halfKey; 
        int halfIndex <- tempKeys.size / 2;
        halfKey <- tempKeys[halfIndex]; 
        last->keys.resizehalfIndex;
        last->childs.resizehalfIndex + 1;
        for int i <- 0; i < halfIndex; i++
            last->keys[i] <- tempKeys[i];
        for int i <- 0; i < halfIndex + 1; i++
            last->childs[i] <- tempchilds[i];
        InNode *newNode <- new InNode;
        for int i <- halfIndex + 1; i < tempKeys.size; i++
            newNode->keys.push_back(tempKeys[i]);
        for int i <- halfIndex + 1; i < tempchilds.size; i++
            newNode->childs.push_back(tempchilds[i]);
        if last = root do
            InNode *newRoot <- new InNode;
            newRoot->keys.push_back(halfKey);
            newRoot->childs.push_back(last);
            newRoot->childs.push_back(newNode);
            root <- newRoot;
            end
        else
            insertInNode(halfKey, findParentroot, last, newNode);
    end 
    
