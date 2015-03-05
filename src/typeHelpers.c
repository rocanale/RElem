#include "R-El.h"

ElDist parseDistText(SEXP dist){
  char *text=(char*) CHAR( STRING_ELT(dist,0) );
  //  printf("The distro is: %s\n",text);
  if (strcmp("MC",text)==0) return EL_MC;
  if (strcmp("MD",text)==0) return EL_MD;
  if (strcmp("MR",text)==0) return EL_MR;
  if (strcmp("VC",text)==0) return EL_VC;
  if (strcmp("VR",text)==0) return EL_VR;
  if (strcmp("STAR",text)==0) return EL_STAR;
  if (strcmp("CIRC",text)==0) return EL_CIRC;
  printf("wrong value: \"%s\", using MC as default\n",text);
  return EL_MC;
}

ElFileFormat parseFormatText(SEXP format){
  char *text=(char*) CHAR( STRING_ELT(format,0) );
  //  printf("The distro is: %s\n",text);
  if (strcmp("AUTO",text)==0) return EL_AUTO;
  if (strcmp("ASCII",text)==0) return EL_ASCII;
  if (strcmp("ASCII_MATLAB",text)==0) return EL_ASCII_MATLAB;
  if (strcmp("BINARY",text)==0) return EL_BINARY;
  if (strcmp("BINARY_FLAT",text)==0) return EL_BINARY_FLAT;
  if (strcmp("EL_BMP",text)==0) return EL_BMP;
  if (strcmp("JPG",text)==0) return EL_JPG;
  if (strcmp("JPEG",text)==0) return EL_JPEG;
  if (strcmp("MATRIX_MARKET",text)==0) return EL_MATRIX_MARKET;
  if (strcmp("PNG",text)==0) return EL_PNG;
  if (strcmp("PPM",text)==0) return EL_PPM;
  if (strcmp("XBM",text)==0) return EL_XBM;
  if (strcmp("XPM",text)==0) return EL_XPM;
  printf("wrong value: \"%s\", using AUTO as default\n",text);
  return EL_AUTO;
}



const char * parseDistEnum(ElDist dist){
  switch(dist){
  case EL_MC: return "MC";
  case EL_MD: return "MD";
  case EL_MR: return "MR";
  case EL_VC: return "VC";
  case EL_VR: return "VR";
  case EL_STAR: return "STAR";
  case EL_CIRC: return "CIRC";
  default: return "N/A";
  }
}

ElUpperOrLower parseUpLo(SEXP uplo){
  char *text = (char*)toChar_p(uplo);
  if (strcmp("L", text) == 0) return EL_LOWER;
  if (strcmp("LOWER", text) == 0) return EL_LOWER;
  if (strcmp("U", text) == 0) return EL_UPPER;
  if (strcmp("UPPER", text) == 0) return EL_UPPER;
  printf("wrong value: using LOWER as default");
  return EL_LOWER;
}

ElOrientation parseOrientation(SEXP orientation){
  char *text = (char*)toChar_p(orientation);
  if (strcmp("N", text) == 0) return EL_NORMAL;
  if (strcmp("NORMAL", text) == 0) return EL_NORMAL;
  if (strcmp("T", text) == 0) return EL_TRANSPOSE;
  if (strcmp("TRANSPOSE", text) == 0) return EL_TRANSPOSE;
  if (strcmp("A", text) == 0) return EL_ADJOINT;
  if (strcmp("ADJOINT", text) == 0) return EL_ADJOINT;
  return EL_NORMAL;
}

ElLeftOrRight parseSide(SEXP side){
  char *text = (char*)toChar_p(side);
  if (strcmp("L", text) == 0) return EL_LEFT;
  if (strcmp("LEFT", text) == 0) return EL_LEFT;
  if (strcmp("R", text) == 0) return EL_RIGHT;
  if (strcmp("RIGHT", text) == 0) return EL_RIGHT;
  return EL_LEFT;
}

ElUnitOrNonUnit parseUnit(SEXP unit){
  char *text = (char*)toChar_p(unit);
  if (strcmp("N", text) == 0) return EL_NON_UNIT;
  if (strcmp("NON_UNIT", text) == 0) return EL_NON_UNIT;
  if (strcmp("U", text) == 0) return EL_UNIT;
  if (strcmp("UNIT", text) == 0) return EL_UNIT;
  return EL_NON_UNIT;
}

ElSortType parseSort(SEXP sort){
  char *text = (char*)toChar_p(sort);
  if (strcmp("U", text) == 0) return EL_UNSORTED;
  if (strcmp("UNSORTED", text) == 0) return EL_UNSORTED;
  if (strcmp("D", text) == 0) return EL_DESCENDING;
  if (strcmp("DESCENDING", text) == 0) return EL_DESCENDING;
  if (strcmp("A", text) == 0) return EL_ASCENDING;
  if (strcmp("ASCENDING", text) == 0) return EL_ASCENDING;
  return EL_UNSORTED;
}

ElRidgeAlg parseRidgeAlg(SEXP alg){
  char *text = (char*)toChar_p(alg);
  if (strcmp("CHOLESKY", text) == 0) return EL_RIDGE_CHOLESKY;
  if (strcmp("QR", text) == 0) return EL_RIDGE_QR;
  if (strcmp("SVD", text) == 0) return EL_RIDGE_SVD;
  return EL_RIDGE_CHOLESKY;
}

ElTikhonovAlg parseTikhonovAlg(SEXP alg){
  char *text = (char*)toChar_p(alg);
  if (strcmp("CHOLESKY", text) == 0) return EL_TIKHONOV_CHOLESKY;
  if (strcmp("QR", text) == 0) return EL_TIKHONOV_QR;
  return EL_TIKHONOV_CHOLESKY;
}

ElRegularization parseRegularization(SEXP pen){
  char *text = (char*)toChar_p(pen);
  if (strcmp("NO_PENALTY", text) == 0) return EL_NO_PENALTY;
  if (strcmp("L1_PENALTY", text) == 0) return EL_L1_PENALTY;
  if (strcmp("L2_PENALTY", text) == 0) return EL_L1_PENALTY;
  return EL_NO_PENALTY;
}

ElLPApproach parseLPApproach(SEXP app){
  char *text = (char*)toChar_p(app);
  if (strcmp("LP_ADMM", text) == 0) return EL_LP_ADMM;
  if (strcmp("LP_IPF", text) == 0) return EL_LP_IPF;
  if (strcmp("LP_IPF_SELFDUAL", text) == 0) return EL_LP_IPF_SELFDUAL;
  if (strcmp("LP_MEHROTRA", text) == 0) return EL_LP_MEHROTRA;
  if (strcmp("LP_MEHROTRA_SELFDUAL", text) == 0) return EL_LP_MEHROTRA_SELFDUAL;
  return EL_LP_ADMM;
}


ElIPFLineSearchCtrl_d parseIPFCtrl
(SEXP gamma, SEXP beta, SEXP psi, SEXP stepRatio, SEXP print){
  ElIPFLineSearchCtrl_d ctrl;
  ElIPFLineSearchCtrlDefault_d(&ctrl); // Optional
  ctrl.gamma = toDouble(gamma);
  ctrl.beta = toDouble(beta);
  ctrl.psi = toDouble(psi);
  ctrl.stepRatio = toDouble(stepRatio);
  ctrl.print = toBool(print);
}


ElRange_i parseRange_i(SEXP beg, SEXP end){
  ElRange_i range;
  range.beg = toElInt(beg);
  range.end = toElInt(end);
  return range;
}



bool isDestroyed(SEXP Rptr){
  return !isNull(getAttrib(Rptr, install("destroyed")));
}


SEXP checkDestroyed(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP,1) );
  LOGICAL(ans)[0] = isDestroyed(Rptr);
  UNPROTECT(1);
  return ans;
}

