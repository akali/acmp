  var bug_d=0,bug_r=1,bug_u=2,bug_l=3,black=4,wall=5,door=6,
      kx=1,ky=1,n=0,go=0,speed=32,dir=0,plus=0,
      M=new Array
      L=new Array

  function DrawBug(x,y,k){
    var gif="bug_u"
    if(k==0) gif="bug_d"
    if(k==1) gif="bug_r"
    if(k==2) gif="bug_u"
    if(k==3) gif="bug_l"    
	gif="/images/bug/"+gif+".gif"
	bug.src=gif
	bug.style.posLeft=x*20+6
	bug.style.posTop=y*20-166-plus*20
  }

  function DrawMap(map){
    for(i=0;i<8;i++){
      M[i]=new Array
      L[i]=new Array
    }
	Restart(map)
	ShowSpeed()
  }

  function Restart(map){
    kx=1;ky=1;go=0;dir=0
    for(i=0;i<8;i++)
      for(j=0;j<30;j++) M[i][j]=1000000000*parseInt(map.charAt(j*8+i))
	myform.start.src='/images/bug/start.gif'
	myform.start.alt='Старт'
	DrawBug(1,1,bug_u)
  }

  function Handle(x,y){
    if((x*y==0)||(x==29)||(y==7)){
      alert('Стены не разбирать!')
	  return
	}
	if(go){alert('Во время движения жука ничего менять нельзя!');return;}
	if((x==28)&&(y==6)){
      alert('Выход не замуровывать!')
	  return
	}
	var p=x*8+y
    if(M[y][x]){
	  map=map.substring(0,p)+'0'+map.substring(p+1,map.length);
	  M[y][x]=0; eval('m'+y+'_'+x+'.src="/images/bug/black.gif"');
	}else{
	  map=map.substring(0,p)+'1'+map.substring(p+1,map.length);
	  M[y][x]=1000000000; eval('m'+y+'_'+x+'.src="/images/bug/wall.gif"');
	}
    if(!ExitExist()){
	  alert('Жучка не замуровывать!')
      Handle(x,y)
	}
  }

//существует ли выход из лабиринта?
function ExitExist(){
  var i,j,k,Ok
  for(i=0;i<8;i++)
    for(j=0;j<30;j++) L[i][j]=M[i][j];
  L[1][1]=1
  do{
    Ok=false
    for(i=1;i<7;i++)
      for(j=1;j<29;j++)
      if((!L[i][j])&&((L[i-1][j]==1)||(L[i+1][j]==1)||(L[i][j-1]==1)||(L[i][j+1]==1))){
        Ok=true
        L[i][j]=1
        if((i==6)&&(j==28)) return true
      }
  }while(Ok)
  return false
}
//Один ход движения жучка
function MakeMove(){
 var kx2,ky2,down,right,up,left,cur,l,nn=speed;
 if(!go) return;
 do{
  nn*=2 
  if((kx==28)&&(ky==6)){
    score.innerHTML=n
    Restart(map)
	return
  }else{
    kx2=kx; ky2=ky; n++
    if((speed>16)||(n%parseInt(16/speed)==0))score.innerHTML=n
    down=M[ky+1][kx]
    right=M[ky][kx+1]
    up=M[ky-1][kx]
    left=M[ky][kx-1]
    if(dir==0) cur=down
    if(dir==1) cur=right
    if(dir==2) cur=up
    if(dir==3) cur=left
    if((cur<=down)&&(cur<=right)&&(cur<=up)&&(cur<=left)){
      if(dir==0) ky2++
      if(dir==1) kx2++
      if(dir==2) ky2--
      if(dir==3) kx2--
	}else
    if((down<=right)&&(down<=up)&&(down<=left)){ky2++;dir=0}else
    if((right<=down)&&(right<=up)&&(right<=left)){kx2++;dir=1}else
    if((up<=right)&&(up<=down)&&(up<=left)){ky2--;dir=2}else
    if((left<=right)&&(left<=down)&&(left<=up)){kx2--;dir=3}
    M[ky][kx]++
    kx=kx2;ky=ky2
  } 
 }while(nn<2)
  DrawBug(kx2,ky2,dir)
  window.setTimeout('MakeMove()',speed)
}

function ShowSpeed(){
  myspeed.innerHTML=11-Math.log(speed)/Math.log(2)
}

DrawMap(map)

