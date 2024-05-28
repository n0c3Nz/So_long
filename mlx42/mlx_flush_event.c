#include	"mlx_int.h"
int	mlx_flush_event(t_xvar *xvar)
{
  XEvent	ev;
  while (XPending(xvar->display))
  {
     XNextEvent(xvar->display,&ev);
  }
}