    #include <allegro.h>
    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    #include<conio.h>
    
    void init();
    void deinit();
    
    int main() {
    	init();
    	BITMAP *carta[10];
    	BITMAP *tela;
    	BITMAP *tabuleiro;
    	PALLETE pal;
    
    	int mx,
            my,
            i,
            j;
        int fx,
            fy,
            mouse_a,
            position_m;
        //Espaçamento inicial das cartas e os eixos
        fx=10;
        fy=15;
        //Inicia fontes
    
    	//Inicia os bitmaps(carrega todos)
    	tela         =create_bitmap(800,600);
        tela         =load_bitmap("./images/inicial.bmp",pal);
       	tabuleiro    =create_bitmap(800,600);
        tabuleiro    =load_bitmap("./images/tabuleiro.bmp",pal);
        
        //carrega as cartas em um vetor
        for(i=0;i<5;i++){
            carta[i]=load_bitmap("./images/cartas.bmp",pal);                  
        }
         
        //Mostra o ponteiro do mouse
        show_mouse(screen);
    	mx=my=-1;
    	
    	//Mostra o bitmap menu
    	blit(tela,screen,0,0,0,0,800,600);
    
        //===========Jogo (Loop-Principal)===================
    	while (!key[KEY_ESC]) {
    
     	    //inicializa o jogo
             if(key[KEY_SPACE]){
              //limpa a tela e escreve o bitmap do tabuleiro
              clear(screen);
              blit(tabuleiro,screen,0,0,0,0,800,600);
              
              //mostra as cartas
              for(i=0;i<2;i++){
                for(j=0;j<4;j++){
                 blit(carta[j],tabuleiro,0,0,fx,fy,140,238);
                 fx+=150;
                }
                 fx=10;
                 fy+=248;
              }
              //Pausa
              clear_keybuf();
              readkey();
            
            //Captura eventos do mouse
            
            if(mouse_a & 0){
              position_m=;
            }
            }
        }
             
     
    
    	deinit();
    	return 0;
    
    }
    END_OF_MAIN()
    void init() {
    	int depth, res;
    	allegro_init();
    	depth = desktop_color_depth();
    	if (depth == 0) depth = 32;
    	set_color_depth(depth);
    	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    	if (res != 0) {
    		allegro_message(allegro_error);
    		exit(-1);
    	}
    
    	install_timer();
    	install_keyboard();
    	install_mouse();
    	/* add other initializations here */
    }
    
    void deinit() {
    	clear_keybuf();
    	/* add other deinitializations here */
    }
    
