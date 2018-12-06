/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

#include<stdio.h>
#include <string.h>
#include "lisatalk.h"
#ifdef Windows
#include "promguess.h"
#else
#include "promguess.h"
#endif


float promguess_wagon_comp(promguess_struct& st) { 



  float result;

  if (debuglevel > 1) {
    fprintf(errfile,"Is WAKZENT = 0? "); fflush(errfile) ;
  }
  if (strcmp(st.WAKZENT,"0") == 0) {
    if (debuglevel > 1) {
      fprintf(errfile,"Yes"); fflush(errfile) ;
    }
    if (debuglevel > 1) {
      fprintf(errfile,"Is LAUT = @? "); fflush(errfile) ;
    }
    if (strcmp(st.LAUT,"@") == 0) {
      if (debuglevel > 1) {
	fprintf(errfile,"Yes"); fflush(errfile) ;
      }
      if (debuglevel > 1) {
	fprintf(errfile,"Is FACCE = 0? "); fflush(errfile) ;
      }
      if (strcmp(st.FACCE,"0") == 0) {
	if (debuglevel > 1) {
	  fprintf(errfile,"Yes"); fflush(errfile) ;
	}
	if (debuglevel > 1) {
	  fprintf(errfile,"Is WORTART = 20? "); fflush(errfile) ;
	}
	if (strcmp(st.WORTART,"20") == 0) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  result = 3.523080 ; } 
	else {
	  if (debuglevel > 1) {
	    fprintf(errfile,"No"); fflush(errfile) ;
	  }
	  result = 4.635000 ; }}
      else {
	if (debuglevel > 1) {
	  fprintf(errfile,"No"); fflush(errfile) ;
	}
	if (debuglevel > 1) {
	  fprintf(errfile,"Is WORTART = 7? "); fflush(errfile) ;
	}
	if (strcmp(st.WORTART,"7") == 0) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is WSYLP = 2? "); fflush(errfile) ;
	  }
	  if (strcmp(st.WSYLP,"2") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    result = 4.116880 ; } 
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    }
	    result = 3.163640 ; }}
	else {
	  if (debuglevel > 1) {
	    fprintf(errfile,"No"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is WSYLP = 2? "); fflush(errfile) ;
	  }
	  if (strcmp(st.WSYLP,"2") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is WORTART = 20? "); fflush(errfile) ;
	    }
	    if (strcmp(st.WORTART,"20") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      result = 3.179780 ; } 
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"No"); fflush(errfile) ;
	      }
	      result = 2.819150 ; }}
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    } 
	    result = 3.336900 ; }}}}
    else {
      if (debuglevel > 1) {
	fprintf(errfile,"No"); fflush(errfile) ;
      }
      if (debuglevel > 1) {
	fprintf(errfile,"Is LAUT = =6? "); fflush(errfile) ;
      }
      if (strcmp(st.LAUT,"=6") == 0) {
	if (debuglevel > 1) {
	  fprintf(errfile,"Yes"); fflush(errfile) ;
	}
	if (debuglevel > 1) {
	  fprintf(errfile,"Is FACCE = 0? "); fflush(errfile) ;
	}
	if (strcmp(st.FACCE,"0") == 0) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  result = 5.451220 ; } 
	else {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is WSYLP = 2? "); fflush(errfile) ;
	  }
	  if (strcmp(st.WSYLP,"2") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    result = 4.527610 ; } 
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No");  fflush(errfile) ;
	    }
	    result = 3.620000 ; }}}
      else {
	if (debuglevel > 1) {
	  fprintf(errfile,"No"); fflush(errfile) ;
	}
	if (debuglevel > 1) {
	  fprintf(errfile,"Is WSYLP = 3? "); fflush(errfile) ;
	}
	if (strcmp(st.WSYLP,"3") == 0) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is WSYLC = 4? "); fflush(errfile) ;
	  }
	  if (strcmp(st.WSYLC,"4") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    result = 13.354000 ; } 
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    }
	    result = 8.758620 ; }}
	else {
	  if (debuglevel > 1) {
	    fprintf(errfile,"No"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is LAUT = I? "); fflush(errfile) ;
	  }
	  if (strcmp(st.LAUT,"I") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is WSYLP = 4? "); fflush(errfile) ;
	    }
	    if (strcmp(st.WSYLP,"4") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      result = 4.483870 ; } 
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"Is WORTART = 7? "); fflush(errfile) ;
	      }
	      if (strcmp(st.WORTART,"7") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		result = 7.942030 ; } 
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"Is FACCE = 0? "); fflush(errfile) ;
		}
		if (strcmp(st.FACCE,"0") == 0) {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  result = 7.241940 ; } 
		else {
		  if (debuglevel > 1) {
		    fprintf(errfile,"No"); fflush(errfile) ;
		  }
		  result = 5.518520 ; }}}}
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is FACCE = 0? "); fflush(errfile) ;
	    }
	    if (strcmp(st.FACCE,"0") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Is WSYLP = 2? "); fflush(errfile) ;
	      }
	      if (strcmp(st.WSYLP,"2") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Is WSYLC = 2? "); fflush(errfile) ;
		}
		if (strcmp(st.WSYLC,"2") == 0) {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  result = 9.527030 ; } 
		else {
		  if (debuglevel > 1) {
		    fprintf(errfile,"No"); fflush(errfile) ;
		  }
		  result = 10.263900 ; }}
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		result = 12.769200 ; }}
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"No"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Is LAUT = U? "); fflush(errfile) ;
	      }
	      if (strcmp(st.LAUT,"U") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Is WORTART = 8? "); fflush(errfile) ;
		}
		if (strcmp(st.WORTART,"8") == 0) {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  result = 2.080000 ; } 
		else {
		  if (debuglevel > 1) {
		    fprintf(errfile,"No"); fflush(errfile) ;
		  }
		  result = 6.641790 ; }}
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Is LAUT = o:? "); fflush(errfile) ;
		}
		if (strcmp(st.LAUT,"o:") == 0) {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  result = 5.898310 ; } 
		else {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Is WSYLP = 2? "); fflush(errfile) ;
		  }
		  if (strcmp(st.WSYLP,"2") == 0) {
		    if (debuglevel > 1) {
		      fprintf(errfile,"Yes"); fflush(errfile) ;
		    }
		    if (debuglevel > 1) {
		      fprintf(errfile,"Yes"); fflush(errfile) ;
		    }
		    result = 7.736360 ; } 
		  else {
		    if (debuglevel > 1) {
		      fprintf(errfile,"Is WSYLC = 3? "); fflush(errfile) ;
		    }
		    if (strcmp(st.WSYLC,"3") == 0) {
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      result = 7.811590 ; } 
		    else {
		      if (debuglevel > 1) {
			fprintf(errfile,"Is WSYLC = 2? "); fflush(errfile) ;
		      }
		      if (strcmp(st.WSYLC,"2") == 0) {
			if (debuglevel > 1) {
			  fprintf(errfile,"Yes"); fflush(errfile) ;
			}
			if (debuglevel > 1) {
			  fprintf(errfile,"Yes"); fflush(errfile) ;
			}
			result = 8.313730 ; } 
		      else {
			if (debuglevel > 1) {
			  fprintf(errfile,"No"); fflush(errfile) ;
			}
			result = 12.822600 ; }}}}}}}}}}}
  else {
    if (debuglevel > 1) {
      fprintf(errfile,"No"); fflush(errfile) ;
    }
    if (debuglevel > 1) {
      fprintf(errfile,"Is WSYLC = 1? "); fflush(errfile) ;
    }
    if (strcmp(st.WSYLC,"1") == 0) {
      if (debuglevel > 1) {
	fprintf(errfile,"Yes"); fflush(errfile) ;
      }
      if (debuglevel > 1) {
	fprintf(errfile,"Is FACCE = 0? "); fflush(errfile) ;
      }
      if (strcmp(st.FACCE,"0") == 0) {
	if (debuglevel > 1) {
	  fprintf(errfile,"Yes"); fflush(errfile) ;
	}
	if (debuglevel > 1) {
	  fprintf(errfile,"Is WORTART = 7? "); fflush(errfile) ;
	}
	if (strcmp(st.WORTART,"7") == 0) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  result = 22.287500 ; } 
	else {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is LAUT = I? "); fflush(errfile) ;
	  }
	  if (strcmp(st.LAUT,"I") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    result = 12.884600 ; } 
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is WORTART = 6? "); fflush(errfile) ;
	    }
	    if (strcmp(st.WORTART,"6") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      result = 20.710501 ; } 
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
	      }
	      if (strcmp(st.PACCE,"0") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		result = 16.079399 ; } 
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		result = 18.201300 ; }}}}}
      else {
	if (debuglevel > 1) {
	  fprintf(errfile,"No"); fflush(errfile) ;
	}
	if (debuglevel > 1) {
	  fprintf(errfile,"Is WORTART = 1? "); fflush(errfile) ;
	}
	if (strcmp(st.WORTART,"1") == 0) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
	  }
	  if (strcmp(st.PACCE,"0") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    result = 6.471540 ; } 
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    }
	    result = 4.596060 ; }}
	else {
	  if (debuglevel > 1) {
	    fprintf(errfile,"No"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is WORTART = 0? "); fflush(errfile) ;
	  }
	  if (strcmp(st.WORTART,"0") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
	    }
	    if (strcmp(st.PACCE,"0") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      result = 8.008470 ; } 
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"Is LAUT = I? "); fflush(errfile) ;
	      }
	      if (strcmp(st.LAUT,"I") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		result = 5.173080 ; } 
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		result = 5.708740 ; }}}
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is WORTART = 7? "); fflush(errfile) ;
	    }
	    if (strcmp(st.WORTART,"7") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      result = 19.256800 ; } 
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"Is WORTART = 20? "); fflush(errfile) ;
	      }
	      if (strcmp(st.WORTART,"20") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
		}
		if (strcmp(st.PACCE,"0") == 0) {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  result = 17.241400 ; } 
		else {
		  if (debuglevel > 1) {
		    fprintf(errfile,"No"); fflush(errfile) ;
		  }
		  result = 14.912300 ; }}
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Is LAUT = I? "); fflush(errfile) ;
		}
		if (strcmp(st.LAUT,"I") == 0) {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  if (debuglevel > 1) {
		    fprintf(errfile,"Is WORTART = 9? "); fflush(errfile) ;
		  }
		  if (strcmp(st.WORTART,"9") == 0) {
		    if (debuglevel > 1) {
		      fprintf(errfile,"Yes"); fflush(errfile) ;
		    }
		    if (debuglevel > 1) {
		      fprintf(errfile,"Yes"); fflush(errfile) ;
		    }
		    result = 7.711340 ; } 
		  else {
		    if (debuglevel > 1) {
		      fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
		    }
		    if (strcmp(st.PACCE,"0") == 0) {
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      result = 12.412500 ; } 
		    else {
		      if (debuglevel > 1) {
			fprintf(errfile,"No"); fflush(errfile) ;
		      }
		      result = 9.379310 ; }}}
		else {
		  if (debuglevel > 1) {
		    fprintf(errfile,"No"); fflush(errfile) ;
		  }
		  if (debuglevel > 1) {
		    fprintf(errfile,"Is WORTART = 9? "); fflush(errfile) ;
		  }
		  if (strcmp(st.WORTART,"9") == 0) {
		    if (debuglevel > 1) {
		      fprintf(errfile,"Yes"); fflush(errfile) ;
		    }
		    if (debuglevel > 1) {
		      fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
		    }
		    if (strcmp(st.PACCE,"0") == 0) {
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      if (debuglevel > 1) {
			fprintf(errfile,"Is LAUT = i:? "); fflush(errfile) ;
		      }
		      if (strcmp(st.LAUT,"i:") == 0) {
			if (debuglevel > 1) {
			  fprintf(errfile,"Yes"); fflush(errfile) ;
			}
			if (debuglevel > 1) {
			  fprintf(errfile,"Yes"); fflush(errfile) ;
			}
			result = 10.872300 ; } 
		      else {
			if (debuglevel > 1) {
			  fprintf(errfile,"No"); fflush(errfile) ;
			}
			result = 14.031500 ; }}
		    else {
		      if (debuglevel > 1) {
			fprintf(errfile,"No"); fflush(errfile) ;
		      }
		      if (debuglevel > 1) {
			fprintf(errfile,"No"); fflush(errfile) ;
		      }
		      result = 9.422860 ; }}
		  else {
		    if (debuglevel > 1) {
		      fprintf(errfile,"No"); fflush(errfile) ;
		    }
		    if (debuglevel > 1) {
		      fprintf(errfile,"Is LAUT = U? "); fflush(errfile) ;
		    }
		    if (strcmp(st.LAUT,"U") == 0) {
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      result = 9.387100 ; } 
		    else {
		      if (debuglevel > 1) {
			fprintf(errfile,"Is LAUT = O? "); fflush(errfile) ;
		      }
		      if (strcmp(st.LAUT,"O") == 0) {
			if (debuglevel > 1) {
			  fprintf(errfile,"Yes"); fflush(errfile) ;
			}
			if (debuglevel > 1) {
			  fprintf(errfile,"Yes"); fflush(errfile) ;
			}
			result = 10.776100 ; } 
		      else {
			if (debuglevel > 1) {
			  fprintf(errfile,"Is WORTART = 4? "); fflush(errfile) ;
			}
			if (strcmp(st.WORTART,"4") == 0) {
			  if (debuglevel > 1) {
			    fprintf(errfile,"Yes"); fflush(errfile) ;
			  }
			  if (debuglevel > 1) {
			    fprintf(errfile,"Yes"); fflush(errfile) ;
			  }
			  result = 11.845200 ; } 
			else {
			  if (debuglevel > 1) {
			    fprintf(errfile,"Is LAUT = a? "); fflush(errfile) ;
			  }
			  if (strcmp(st.LAUT,"a") == 0) {
			    if (debuglevel > 1) {
			      fprintf(errfile,"Yes"); fflush(errfile) ;
			    }
			    if (debuglevel > 1) {
			      fprintf(errfile,"Yes"); fflush(errfile) ;
			    }
			    result = 12.523300 ; } 
			  else {
			    if (debuglevel > 1) {
			      fprintf(errfile,"Is LAUT = a:? "); fflush(errfile) ;
			    }
			    if (strcmp(st.LAUT,"a:") == 0) {
			      if (debuglevel > 1) {
				fprintf(errfile,"Yes"); fflush(errfile) ;
			      }
			      if (debuglevel > 1) {
				fprintf(errfile,"Yes"); fflush(errfile) ;
			      }
			      result = 13.593200 ; } 
			    else {
			      if (debuglevel > 1) {
				fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
			      }
			      if (strcmp(st.PACCE,"0") == 0) {
				if (debuglevel > 1) {
				  fprintf(errfile,"Yes"); fflush(errfile) ;
				}
				if (debuglevel > 1) {
				  fprintf(errfile,"Yes"); fflush(errfile) ;
				}
				result = 18.229500 ; } 
			      else {
				if (debuglevel > 1) {
				  fprintf(errfile,"No"); fflush(errfile) ;
				}
				result = 16.187500 ; }}}}}}}}}}}}}}
    else {
      if (debuglevel > 1) {
	fprintf(errfile,"No"); fflush(errfile) ;
      }
      if (debuglevel > 1) {
	fprintf(errfile,"Is WSYLC = 2? "); fflush(errfile) ;
      }
      if (strcmp(st.WSYLC,"2") == 0) {
	if (debuglevel > 1) {
	  fprintf(errfile,"Yes"); fflush(errfile) ;
	}
	if (debuglevel > 1) {
	  fprintf(errfile,"Is WORTART = 7? "); fflush(errfile) ;
	}
	if (strcmp(st.WORTART,"7") == 0) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is LAUT = a? "); fflush(errfile) ;
	  }
	  if (strcmp(st.LAUT,"a") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    } 
	    result = 22.428600 ; } 
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is FACCE = 0? "); fflush(errfile) ;
	    }
	    if (strcmp(st.FACCE,"0") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      result = 21.695400 ; } 
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"No"); fflush(errfile) ;
	      }
	      result = 20.858400 ; }}}
	else {
	  if (debuglevel > 1) {
	    fprintf(errfile,"No"); fflush(errfile) ;
	  } 
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is WORTART = 1? "); fflush(errfile) ;
	  }
	  if (strcmp(st.WORTART,"1") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    result = 16.197500 ; } 
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is WORTART = 8? "); fflush(errfile) ;
	    }
	    if (strcmp(st.WORTART,"8") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      result = 20.753201 ; } 
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"Is LAUT = E? "); fflush(errfile) ;
	      }
	      if (strcmp(st.LAUT,"E") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		result = 20.134600 ; } 
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"Is LAUT = aU? "); fflush(errfile) ;
		}
		if (strcmp(st.LAUT,"aU") == 0) {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  if (debuglevel > 1) {
		    fprintf(errfile,"Yes"); fflush(errfile) ;
		  }
		  result = 20.823500 ; } 
		else {
		  if (debuglevel > 1) {
		    fprintf(errfile,"Is FACCE = 0? "); fflush(errfile) ;
		  }
		  if (strcmp(st.FACCE,"0") == 0) {
		    if (debuglevel > 1) {
		      fprintf(errfile,"Yes"); fflush(errfile) ;
		    }
		    if (debuglevel > 1) {
		      fprintf(errfile,"Is WORTART = 20? ");
		    }
		    if (strcmp(st.WORTART,"20") == 0) {
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      if (debuglevel > 1) {
			fprintf(errfile,"Yes"); fflush(errfile) ;
		      }
		      result = 18.763399 ; } 
		    else {
		      if (debuglevel > 1) {
			fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
		      }
		      if (strcmp(st.PACCE,"0") == 0) {
			if (debuglevel > 1) {
			  fprintf(errfile,"Yes"); fflush(errfile) ;
			}
			if (debuglevel > 1) {
			  fprintf(errfile,"Yes"); fflush(errfile) ;
			}
			result = 16.812500 ; } 
		      else {
			if (debuglevel > 1) {
			  fprintf(errfile,"No"); fflush(errfile) ;
			}
			result = 17.889900 ; }}}
		  else {
		    if (debuglevel > 1) {
		      fprintf(errfile,"No"); fflush(errfile) ;
		    }
		    if (debuglevel > 1) {
		      fprintf(errfile,"No"); fflush(errfile) ;
		    }
		    result = 19.360701 ; }}}}}}}
      else {
	if (debuglevel > 1) {
	  fprintf(errfile,"No"); fflush(errfile) ;
	}
	if (debuglevel > 1) {
	  fprintf(errfile,"Is WSYLC = 4? "); fflush(errfile) ;
	}
	if (strcmp(st.WSYLC,"4") == 0) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"Yes"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
	  }
	  if (strcmp(st.PACCE,"0") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    result = 24.322599 ; } 
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    }
	    result = 22.861099 ; }}
	else {
	  if (debuglevel > 1) {
	    fprintf(errfile,"No"); fflush(errfile) ;
	  }
	  if (debuglevel > 1) {
	    fprintf(errfile,"Is PACCE = 0? "); fflush(errfile) ;
	  } 
	  if (strcmp(st.PACCE,"0") == 0) {
	    if (debuglevel > 1) {
	      fprintf(errfile,"Yes"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is WSYLP = 2? "); fflush(errfile) ;
	    }
	    if (strcmp(st.WSYLP,"2") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      result = 20.031700 ; } 
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"Is WORTART = 7? "); fflush(errfile) ;
	      }
	      if (strcmp(st.WORTART,"7") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		result = 21.745800 ; } 
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		result = 20.393400 ; }}}
	  else {
	    if (debuglevel > 1) {
	      fprintf(errfile,"No"); fflush(errfile) ;
	    }
	    if (debuglevel > 1) {
	      fprintf(errfile,"Is WORTART = 7? "); fflush(errfile) ;
	    }
	    if (strcmp(st.WORTART,"7") == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Yes"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Is WSYLP = 1? "); fflush(errfile) ;
	      }
	      if (strcmp(st.WSYLP,"1") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		result = 23.181801 ; } 
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		result = 22.109600 ; }}
	    else {
	      if (debuglevel > 1) {
		fprintf(errfile,"No"); fflush(errfile) ;
	      }
	      if (debuglevel > 1) {
		fprintf(errfile,"Is WORTART = 20? "); fflush(errfile) ;
	      }
	      if (strcmp(st.WORTART,"20") == 0) {
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes"); fflush(errfile) ;
		}
		if (debuglevel > 1) {
		  fprintf(errfile,"Yes");
		} fflush(errfile) ;
		result = 22.491199 ; } 
	      else {
		if (debuglevel > 1) {
		  fprintf(errfile,"No"); fflush(errfile) ;
		}
		result = 21.333300 ; }}}}}}}
  if (debuglevel > 1) {
    fprintf(errfile,"%c",0x0a); fflush(errfile) ;
  }
  return(result) ; }





