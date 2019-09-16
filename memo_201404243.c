#include <linux/proc_fs.h>
#include <linux/seq_file.h> 
#include <asm/uaccess.h> 
#include <linux/hugetlb.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>   
#include <linux/fs.h>

#define BUFSIZE  	150

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Escribir informaciond de la memoria ram.");
MODULE_AUTHOR("Bryan Ordonez -  201404243");

struct sysinfo inf;

static int escribir_archivo(struct seq_file * archivo, void *v) {	
    si_meminfo(&inf);
    long total_memoria 	= (inf.totalram * 4);
    long memoria_libre 	= (inf.freeram * 4 );
    seq_printf(archivo, " __________________________________________________\n");
    seq_printf(archivo, "| Lab. Sistemas Operativos 1                       |\n");
    seq_printf(archivo, "| Segundo Semestre 2019                            |\n");
    seq_printf(archivo, "| Bryan Otoniel Ordoñez Morales                    |\n");
    seq_printf(archivo, "| 2014-04243                                       |\n");
    seq_printf(archivo, "|                                                  |\n");
    seq_printf(archivo, "|    PRACTICA 2 (MODULO 1 - MEMORIA RAM)           |\n");
    seq_printf(archivo, "|__________________________________________________|\n");
    seq_printf(archivo, "  Sistema Operativo: CentOS 7\n");
    seq_printf(archivo, "  Memoria Total : \t %8lu KB - %8lu MB\n",total_memoria, total_memoria / 1024);
    seq_printf(archivo, "  Memoria Libre : \t %8lu KB - %8lu MB \n", memoria_libre, memoria_libre / 1024);
    seq_printf(archivo, "  Memoria en uso: \t %i %%\n", (memoria_libre * 100)/total_memoria) ;
    return 0;
}

static int al_abrir(struct inode *inode, struct  file *file) {
  return single_open(file, escribir_archivo, NULL);
}

static struct file_operations operaciones =
{    
    .open = al_abrir,
    .read = seq_read
};

static int iniciar(void)
{
    proc_create("memo_201404243", 0, NULL, &operaciones);
    printk(KERN_INFO "Carnet: 2014-04243\n");
    return 0;
}
 
static void salir(void)
{
    remove_proc_entry("memo_201404243", NULL);
    printk(KERN_INFO "Curso: Sistemas Operativos 1\n");
}
 
module_init(iniciar);
module_exit(salir); 
