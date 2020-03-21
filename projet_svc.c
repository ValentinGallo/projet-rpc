/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "projet.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
projet_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		personne enregistrer_adherent_1_arg;
		int renouveler_adhesion_1_arg;
		int lister_outils_1_arg;
		param_outil louer_outil_1_arg;
		param_poste reserver_poste_1_arg;
		param_paiement effectuer_paiement_1_arg;
		int retour_location_1_arg;
		int signaler_anomalie_1_arg;
		int corriger_anomalie_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case INIT:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) init_1_svc;
		break;

	case enregistrer_adherent:
		_xdr_argument = (xdrproc_t) xdr_personne;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) enregistrer_adherent_1_svc;
		break;

	case renouveler_adhesion:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) renouveler_adhesion_1_svc;
		break;

	case lister_outils:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_tab_outils;
		local = (char *(*)(char *, struct svc_req *)) lister_outils_1_svc;
		break;

	case lister_postes:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_tab_postes;
		local = (char *(*)(char *, struct svc_req *)) lister_postes_1_svc;
		break;

	case louer_outil:
		_xdr_argument = (xdrproc_t) xdr_param_outil;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) louer_outil_1_svc;
		break;

	case reserver_poste:
		_xdr_argument = (xdrproc_t) xdr_param_poste;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) reserver_poste_1_svc;
		break;

	case tarifs_horaires:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_informations;
		local = (char *(*)(char *, struct svc_req *)) tarifs_horaires_1_svc;
		break;

	case afficher_mode_paiement:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_tab_paiements;
		local = (char *(*)(char *, struct svc_req *)) afficher_mode_paiement_1_svc;
		break;

	case effectuer_paiement:
		_xdr_argument = (xdrproc_t) xdr_param_paiement;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) effectuer_paiement_1_svc;
		break;

	case retour_location:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) retour_location_1_svc;
		break;

	case signaler_anomalie:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) signaler_anomalie_1_svc;
		break;

	case corriger_anomalie:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) corriger_anomalie_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (PROJET, GEOM_VERSION_1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, PROJET, GEOM_VERSION_1, projet_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (PROJET, GEOM_VERSION_1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, PROJET, GEOM_VERSION_1, projet_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (PROJET, GEOM_VERSION_1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
