FILE *fp;
    fp = fopen("banData.txt","a");
    fprintf(fp,"getAns\n");
    for( i=0 ; i<9 ; i++ )
    {
    	for( j=0 ; j<9 ; j++ )
    	{
    	    fprintf(fp,"%d ",ban[i][j]);
    	}
    	fprintf(fp,"\n");
    }
    fprintf(fp,"ans=%d x=%d y=%d ban[x][y]=%d",ans,x,y,ban[x][y]);
    
FILE *fp;
    fp = fopen("banData.txt","a");
    fprintf(fp,"BanSpace\n");
    for( i=0 ; i<9 ; i++ )
    {
    	for( j=0 ; j<9 ; j++ )
    	{
    	    fprintf(fp,"%d ",ban[i][j]);
    	}
    	fprintf(fp,"\n");
    }

FILE *fp;
    fp = fopen("banData.txt","a");
    fprintf(fp,"display\n");
    for( i=0 ; i<9 ; i++ )
    {
    	for( j=0 ; j<9 ; j++ )
    	{
    	    fprintf(fp,"%d ",ban[i][j]);
    	}
    	fprintf(fp,"\n");
    }
    
FILE *fp;
    fp = fopen("banData.txt","a");
    fprintf(fp,"sukodu\n");
    for( i=0 ; i<9 ; i++ )
    {
    	for( j=0 ; j<9 ; j++ )
    	{
    	    fprintf(fp,"%d ",sukodu[i][j]);
    	}
    	fprintf(fp,"\n");
    }
    
FILE *fp;
    fp = fopen("banData.txt","a");
    fprintf(fp,"initialize\n");
    for( i=0 ; i<9 ; i++ )
    {
    	for( j=0 ; j<9 ; j++ )
    	{
    	    fprintf(fp,"%d ",ban[i][j]);
    	}
    	fprintf(fp,"\n");
    }
