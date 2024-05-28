#include	"mlx_int.h"
int	mlx_int_wait_first_expose(t_xvar *xvar,Window win)
{
  XEvent	ev;
  XWindowEvent(xvar->display,win,ExposureMask,&ev);
  XPutBackEvent(xvar->display,&ev);
}