int GetHeight( BinTree BT ){
    if(BT == NULL)
        return 0;
    int l = GetHeight(BT->Left),r = GetHeight(BT->Right),max;
    if(l > r)
        max = l +1;
    else
        max = r +1;
    return  max;
}
void PreorderPrintLeaves( BinTree BT ){
    if(BT){
        if(!(BT-> Left||BT->Right))
            printf(" %c",BT->Data);
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
}
