#include <stdlib.h>
#include <stdbool.h>
#include ".././headers/echiquier.h"
#include ".././headers/piece.h"

bool CaseExiste(int x,int y){
    if(x<=8 && x>=1 && y<=8 && y>=1){
        return true;
    }
    return false;
}

void calculAtteignablePion(Piece* self, Case Plateau[8][8]){
    int xPiece = self->x;
    int yPiece = self->y;

    if (self->couleur == BLANC){                                                                              //Déplacements classique
            insertionListeCaseAtteignables(&Plateau[xPiece+1][yPiece], self->casesAtteignables);
        if(xPiece == 2){
            if(Plateau[xPiece+2][yPiece].piece==NULL){                                                        //Avance de deux s'il est sur la ligne de départ
                insertionListeCaseAtteignables(&Plateau[xPiece+2][yPiece], self->casesAtteignables);
            }
        }
        if(xPiece<8 && yPiece<8 && Plateau[xPiece+1][yPiece+1].piece!=NULL){                                  //Possibilité de manger en diagonale
            insertionListeCaseAtteignables(&Plateau[xPiece+1][yPiece+1], self->casesAtteignables);
        }
        if(xPiece<8 && yPiece>1 && Plateau[xPiece+1][yPiece-1].piece!=NULL){
            insertionListeCaseAtteignables(&Plateau[xPiece+1][yPiece-1], self->casesAtteignables);
        }
    }else{
        if(xPiece >1 && Plateau[xPiece-1][yPiece].piece==NULL){
            insertionListeCaseAtteignables(&Plateau[xPiece-1][yPiece], self->casesAtteignables);
        }
        if(xPiece == 7){
            if(Plateau[xPiece-2][yPiece].piece==NULL){
                insertionListeCaseAtteignables(&Plateau[xPiece-2][yPiece], self->casesAtteignables);
            }
        }
        if(xPiece>1 && yPiece<8 && Plateau[xPiece-1][yPiece+1].piece!=NULL){
            insertionListeCaseAtteignables(&Plateau[xPiece-1][yPiece+1], self->casesAtteignables);
        }
        if(xPiece>1 && yPiece>1 && Plateau[xPiece+1][yPiece-1].piece!=NULL){
            insertionListeCaseAtteignables(&Plateau[xPiece-1][yPiece-1], self->casesAtteignables);
        }
    }
}

void calculAtteignableTour(Piece* self, Case Plateau[8][8]){
    int xPiece = self->x;
    int yPiece = self->y;

    //Tour vers le haut (PDV des blancs)

    while(xPiece<8 && Plateau[xPiece+1][yPiece].piece==NULL){                                      
        insertionListeCaseAtteignables(&Plateau[xPiece+1][yPiece], self->casesAtteignables);
        xPiece++;
    }
    if(xPiece != 7){
        if((Plateau[xPiece+1][yPiece].piece)->couleur != self->couleur){
            insertionListeCaseAtteignables(&Plateau[xPiece+1][yPiece], self->casesAtteignables);
        }
    }
    int xPiece = self->x;

    //Tour vers le bas (PDV des blancs)

    while(xPiece>1 && Plateau[xPiece-1][yPiece].piece==NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece-1][yPiece], self->casesAtteignables);
        xPiece--;
    }
    if(xPiece != 2){
        if((Plateau[xPiece-1][yPiece].piece)->couleur != self->couleur){
            insertionListeCaseAtteignables(&Plateau[xPiece+1][yPiece], self->casesAtteignables);
        }
    }
    int xPiece = self->x;

    //Tour vers la droite (PDV des blancs)

    while(yPiece<8 && Plateau[xPiece][yPiece+1].piece==NULL ){
        insertionListeCaseAtteignables(&Plateau[xPiece][yPiece+1], self->casesAtteignables);
        yPiece++;
    }
    if(yPiece != 7){
        if((Plateau[xPiece][yPiece+1].piece)->couleur != self->couleur){
            insertionListeCaseAtteignables(&Plateau[xPiece][yPiece+1], self->casesAtteignables);
        }
    }
    int yPiece = self->y;

    //Tour vers la gauche (PDV des blancs)

    while(yPiece>1 && Plateau[xPiece][yPiece-1].piece==NULL ){
        insertionListeCaseAtteignables(&Plateau[xPiece][yPiece-1], self->casesAtteignables);
        yPiece--;
    }
    if(yPiece != 2){
        if((Plateau[xPiece][yPiece-1].piece)->couleur != self->couleur){
            insertionListeCaseAtteignables(&Plateau[xPiece][yPiece-1], self->casesAtteignables);
        }
    }
    int yPiece = self->y;

}

void calculAtteignableCavalier(Piece* self, Case Plateau[8][8]){
    int xPiece = self->x;
    int yPiece = self->y;
    if(CaseExiste(xPiece+2,yPiece+1) && Plateau[xPiece+2][yPiece+1].piece == NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece+2][yPiece+1], self->casesAtteignables);
    }
    if(CaseExiste(xPiece+2,yPiece-1) && Plateau[xPiece+2][yPiece-1].piece == NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece+2][yPiece-1], self->casesAtteignables);
    }
    if(CaseExiste(xPiece+1,yPiece+2) && Plateau[xPiece+1][yPiece+2].piece == NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece+1][yPiece+2], self->casesAtteignables);
    }
    if(CaseExiste(xPiece+1,yPiece-2) && Plateau[xPiece+1][yPiece-2].piece == NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece+1][yPiece-2], self->casesAtteignables);
    }
    if(CaseExiste(xPiece-1,yPiece-2) && Plateau[xPiece-1][yPiece-2].piece == NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece-1][yPiece-2], self->casesAtteignables);
    }
    if(CaseExiste(xPiece-1,yPiece+2) && Plateau[xPiece-1][yPiece+2].piece == NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece-1][yPiece+2], self->casesAtteignables);
    }
    if(CaseExiste(xPiece-2,yPiece-1) && Plateau[xPiece-2][yPiece-1].piece == NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece-2][yPiece-1], self->casesAtteignables);
    }
    if(CaseExiste(xPiece-2,yPiece+1) && Plateau[xPiece-2][yPiece+1].piece == NULL){
        insertionListeCaseAtteignables(&Plateau[xPiece-2][yPiece+1], self->casesAtteignables);
    }
}

void calculAtteignableFou(Piece* self, Case Plateau[8][8]){
    
}