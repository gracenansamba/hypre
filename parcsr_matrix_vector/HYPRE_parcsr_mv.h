/*BHEADER**********************************************************************
 * (c) 1998   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/
/******************************************************************************
 *
 * Header file for HYPRE_parcsr_mv library
 *
 *****************************************************************************/

#ifndef HYPRE_PARCSR_MV_HEADER
#define HYPRE_PARCSR_MV_HEADER

#include "HYPRE_utilities.h"

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------
 * Structures
 *--------------------------------------------------------------------------*/

/* this needs to be fixed */
typedef void *HYPRE_ParCSRMatrix;
typedef void *HYPRE_ParVector;

/*--------------------------------------------------------------------------
 * Prototypes
 *--------------------------------------------------------------------------*/

# define        P(s) s

/* HYPRE_parcsr_matrix.c */
HYPRE_ParCSRMatrix HYPRE_CreateParCSRMatrix P((MPI_Comm comm , int global_num_rows , int global_num_cols , int *row_starts , int *col_starts , int num_cols_offd , int num_nonzeros_diag , int num_nonzeros_offd ));
int HYPRE_DestroyParCSRMatrix P((HYPRE_ParCSRMatrix matrix ));
int HYPRE_InitializeParCSRMatrix P((HYPRE_ParCSRMatrix matrix ));
void HYPRE_PrintParCSRMatrix P((HYPRE_ParCSRMatrix matrix , char *file_name ));
int HYPRE_GetRowParCSRMatrix P((HYPRE_ParCSRMatrix matrix, int row, int *size, int ** col_ind, double **values ));
int HYPRE_RestoreRowParCSRMatrix P((HYPRE_ParCSRMatrix matrix, int row, int *size, int ** col_ind, double **values ));
int HYPRE_GetCommParCSR P(( HYPRE_ParCSRMatrix  matrix, MPI_Comm *comm ));
int HYPRE_GetDimsParCSR P(( HYPRE_ParCSRMatrix  matrix, int *M, int *N ));

/* HYPRE_parcsr_vector.c */
HYPRE_ParVector HYPRE_CreateParVector P((MPI_Comm comm , int global_size , int *partitioning ));
int HYPRE_DestroyParVector P((HYPRE_ParVector vector ));
int HYPRE_InitializeParVector P((HYPRE_ParVector vector ));
int HYPRE_PrintParVector P((HYPRE_ParVector vector , char *file_name ));

#undef P

#ifdef __cplusplus
}
#endif

#endif
