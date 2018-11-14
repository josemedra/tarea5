#include "particula.h"
#include "application.h"


    float particula::getposx()
    {
      return px;

    }

    float particula::getposy()
    {
      return py;

    }

    float particula::getvelx()
    {

      return vx;
    }

    float particula::getvely()
    {
        return vy;

    }

    float particula::getradio()
    {
        return r;
    }


    void particula::setvelocidad(float velx, float vely)
    {
          vx= velx;
          vy= vely;

    }

    void particula::setposicion(float x, float y)
    {
          px=x;
          py=y;

    }

    void particula::mover(float dt, float vertlim)
    {
        //Ecuaciones Movimiento Parabolico
        px=vx*cos(alpha*pi/180)*t;
        py=vy*sin(alpha*pi/180)*t-0.5*g*pow(t,2);
        setPos(getposx(),vertlim-getposy());
        t=t+0.2;
    }



    QRectF particula::boundingRect() const
    {

       return QRectF(-1*r,-1*r,2*r,2*r);
    }

    void particula::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
    {
        painter->setBrush(Qt::darkRed);              // Pinta la particula de rojo
        painter->drawEllipse(boundingRect());        // Dibuja una figura eliptica y la encierra en un rectangulo

    }
