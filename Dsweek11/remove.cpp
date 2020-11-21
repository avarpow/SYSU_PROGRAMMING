//algorithm:remove
//输入：key
//输出：无
remove(key)
    if !ready
        return;
    if root = NULL 
        return;
    InNode *now <- root;
    InNode *parent;
    int leftSibling, rightSibling;
    while now->isleave != true do
        for int i <- 0; i < now->keys.size; i++ 
            parent <- now;
            leftSibling <- i - 1;  
            rightSibling <- i + 1; 
        end
            if key < now->keys[i]
                now <- now->childs[i];
                break;
            if i = now->keys.size - 1
                leftSibling <- i;
                rightSibling <- i + 2; 
                now <- now->childs[i + 1];
                break;
    end        
    int pos <- 0;
    bool exist <- false;
    for pos <- 0; pos < now->keys.size; pos++ 
        if now->keys[pos] = key
            exist <- true;
            break;
    end
    vector<Key>::iterator itr <- lower_boundnow->keys.begin, now->keys.end, key;
    int num <- itr - now->keys.begin;
    if itr = now->keys.end
        return;
    char deletefile[10] <- "Deleted";
    strcpynow->stores[num].data, deletefile;
    for int i <- pos; i < now->keys.size - 1; i++
        now->keys[i] <- now->keys[i + 1];
        now->stores[i] <- now->stores[i + 1];
    int prev_size <- now->keys.size;
    now->keys.resizeprev_size - 1;
    now->stores.resizeprev_size - 1;
    if now = root
        if now->keys.size = 0  
            root <- nullptr;
    if now->keys.size >= LeaveNum + 1 / 2
        return;
    if leftSibling >= 0
        InNode *leftNode <- parent->childs[leftSibling];
        if leftNode->keys.size >= LeaveNum + 1 / 2 + 1 do
            int maxIdx <- leftNode->keys.size - 1;
            now->keys.insertnow->keys.begin, leftNode->keys[maxIdx];
            now->stores.insertnow->stores.begin, leftNode->stores[maxIdx];
            leftNode->keys.resizemaxIdx;
            leftNode->stores.resizemaxIdx;
            parent->keys[leftSibling] <- now->keys[0];
            return;
        end    
    if rightSibling < parent->childs.size do
        InNode *rightNode <- parent->childs[rightSibling];
        if rightNode->keys.size >= LeaveNum + 1 / 2 + 1 do
            int minIdx <- 0;
            now->keys.push_back(rightNode->keys[minIdx]);
            now->stores.push_back(rightNode->stores[minIdx]);
            rightNode->keys.eraserightNode->keys.begin;
            rightNode->stores.eraserightNode->stores.begin;
            parent->keys[rightSibling - 1] <- rightNode->keys[0];
            return;
        end
    end
    if leftSibling >= 0 do
        InNode *leftNode <- parent->childs[leftSibling];
        for int i <- 0; i < now->keys.size; i++ do
            leftNode->keys.push_back(now->keys[i]);
            leftNode->stores.push_back(now->stores[i]);
        end
        leftNode->next <- now->next;
        removeInNodeparent->keys[leftSibling], parent, now; 
    end
    elif rightSibling <= parent->keys.size
        InNode *rightNode <- parent->childs[rightSibling];
        for int i <- 0; i < rightNode->keys.size; i++ do
            now->keys.push_back(rightNode->keys[i]);
            now->stores.push_back(rightNode->stores[i]);
        end
        now->next <- rightNode->next;
        removeInNodeparent->keys[rightSibling - 1], parent, rightNode; 
    if leftSibling >= 0 do
        InNode *leftNode <- parent->childs[leftSibling];
        for int i <- 0; i < now->keys.size; i++ do
            leftNode->keys.push_back(now->keys[i]);
            leftNode->stores.push_back(now->stores[i]);
        end
        leftNode->next <- now->next;
        removeInNodeparent->keys[leftSibling], parent, now; 
    end
    elif rightSibling <= parent->keys.size do
        InNode *rightNode <- parent->childs[rightSibling];
        for int i <- 0; i < rightNode->keys.size; i++ do
            now->keys.push_back(rightNode->keys[i]);
            now->stores.push_back(rightNode->stores[i]);
        end
        now->next <- rightNode->next;
        removeInNodeparent->keys[rightSibling - 1], parent, rightNode; 
    end

removeInNode(int x, InNode *cursor, InNode *child)
    InNode *temproot <- root;
    if cursor = temproot 
        if cursor->keys.size = 1 
            if cursor->childs[1] = child
                root <- cursor->childs[0];
                return;
            elif cursor->childs[0] = child
                root <- cursor->childs[1];
                return;
    int pos;
    for pos <- 0; pos < cursor->keys.size; pos++
        if cursor->keys[pos] = x
            break;
    for int i <- pos; i < cursor->keys.size - 1; i++
        cursor->keys[i] <- cursor->keys[i + 1];
    cursor->keys.resizecursor->keys.size - 1;
    for pos <- 0; pos < cursor->childs.size; pos++
        if cursor->childs[pos] = child
            break;
    for int i <- pos; i < cursor->childs.size - 1; i++
        cursor->childs[i] <- cursor->childs[i + 1];
    cursor->childs.resizecursor->childs.size - 1;
    if cursor->keys.size >= MiddleNum + 1 / 2 - 1
        return;
    if cursor = temproot
        return;
    InNode *parent <- findParenttemproot, cursor;;
    int leftSibling, rightSibling;
    for pos <- 0; pos < parent->childs.size; pos++
        if parent->childs[pos] = cursor do  
            leftSibling <- pos - 1;
            rightSibling <- pos + 1;
            break;
        end
    end
    if leftSibling >= 0 do
        InNode *leftNode <- parent->childs[leftSibling];
        if leftNode->keys.size >= MiddleNum + 1 / 2
            int maxIdxKey <- leftNode->keys.size - 1;
            cursor->keys.insertcursor->keys.begin, parent->keys[leftSibling];
            parent->keys[leftSibling] <- leftNode->keys[maxIdxKey];
            int maxIdxPtr <- leftNode->childs.size - 1;
            cursor->childs.insertcursor->childs.begin, leftNode->childs[maxIdxPtr];
            leftNode->keys.resizemaxIdxKey;
            leftNode->stores.resizemaxIdxPtr;
            return;
    end
    if rightSibling < parent->childs.size do
        InNode *rightNode <- parent->childs[rightSibling];
        if rightNode->keys.size >= MiddleNum + 1 / 2
            int maxIdxKey <- rightNode->keys.size - 1;
            cursor->keys.push_back(parent->keys[pos]);
            parent->keys[pos] <- rightNode->keys[0];
            rightNode->keys.eraserightNode->keys.begin;
            cursor->childs.push_back(rightNode->childs[0]);
            cursor->childs.erasecursor->childs.begin;
            return;
    end    
    if leftSibling >= 0 do
        InNode *leftNode <- parent->childs[leftSibling];
        leftNode->keys.push_back(parent->keys[leftSibling]);
        for int val : cursor->keys  
            leftNode->keys.push_back(val);
        for int i <- 0; i < cursor->childs.size; i++
            leftNode->childs.push_back(cursor->childs[i]);
            cursor->childs[i] <- NULL;
        cursor->childs.resize0;
        cursor->keys.resize0;
        removeInNodeparent->keys[leftSibling], parent, cursor;
    end
    elif rightSibling < parent->childs.size
        InNode *rightNode <- parent->childs[rightSibling];
        cursor->keys.push_back(parent->keys[rightSibling - 1]);
        for int val : rightNode->keys
            cursor->keys.push_back(val);
        for int i <- 0; i < rightNode->childs.size; i++
            cursor->childs.push_back(rightNode->childs[i]);
            rightNode->childs[i] <- NULL;
        rightNode->childs.resize0;
        rightNode->keys.resize0;
        removeInNodeparent->keys[rightSibling - 1], parent, rightNode;
    end
end
