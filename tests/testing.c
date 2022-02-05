/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:02:52 by coder             #+#    #+#             */
/*   Updated: 2022/02/05 01:35:38 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <map.h>
#include "./unity/unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testando_is_invalid_arg_sem_parametro(void){
	TEST_ASSERT_EQUAL_INT (FALSE, is_invalid_arg(1, NULL));
}

void testando_com_um_arquivo_sem_ponto_cub(void){
	char *lek[2];
	lek[0] = "./cube";
	lek[1] = "./test.cuba";
	TEST_ASSERT_EQUAL_INT (FALSE, is_invalid_arg(2, lek));
}

void testando_se_o_arquivo_existe(void)
{
	char *lek[2];
	lek[0] = "./cube";
	lek[1] = "./test.cub";
	TEST_ASSERT_EQUAL_INT (FALSE, is_invalid_arg(2, lek));
}

void testando_se_o_arquivo_esta_vazio(void)
{
	TEST_ASSERT_NULL (store_content_map("./maps/empty_map.cub"));
}

void testando_se_o_arquivo_nao_esta_vazio(void)
{
	TEST_ASSERT_NOT_NULL (store_content_map("./maps/valid_map.cub"));
}

void testando_se_os_arquivos_da_textura_existe_e_sao_validos(void)
{
	char **content = store_content_map("./maps/valid_map.cub");
	TEST_ASSERT_NOT_NULL (texture_file_exist(content));
	ft_free_split(content);
}

void testando_se_os_arquivos_da_textura_nao_existe(void)
{
	char **content = store_content_map("./maps/invalid_map.cub");
	TEST_ASSERT_NULL (texture_file_exist(content));
	ft_free_split(content);
}

void testando_se_as_texturas_sao_validas(void)
{
	char **map_content = store_content_map("./maps/valid_map.cub");
	TEST_ASSERT_EQUAL_INT(TRUE, valid_texture(map_content));
	ft_free_split(map_content);
}

void testando_se_as_texturas_nao_sao_validas(void)
{
	char **map_content = store_content_map("./maps/invalid_map.cub");
	TEST_ASSERT_EQUAL_INT(FALSE, valid_texture(map_content));
	ft_free_split(map_content);
}

void testando_se_o_mapa_tem_apenas_os_caracteres_permitidos(void)
{
	char **map_content = store_content_map("./maps/valid_map.cub");
	TEST_ASSERT_EQUAL_INT(TRUE, valid_characters(map_content));
	ft_free_split(map_content);
}

// void testando_se_o_mapa_tem_caracteres_invalidos(void)
// {
// 	char **map_content = store_content_map("./maps/invalid_map.cub");
// 	TEST_ASSERT_EQUAL_INT(FALSE, valid_characters(map_content));
// 	ft_free_split(map_content);
// }

void testando_se_a_borda_do_map_tem_apenas_1(void)
{
	char **map_content = store_content_map("./maps/valid_map.cub");
	TEST_ASSERT_EQUAL_INT(TRUE, valid_edge(map_content));
	ft_free_split(map_content);
}

// void testando_se_a_borda_do_map_esta_invalida(void)
// {
// 	char **map_content = store_content_map("./maps/invalid_map.cub");
// 	TEST_ASSERT_EQUAL_INT(FALSE, valid_edge(map_content));
// 	ft_free_split(map_content);
// }


//void testando_se_dentro_do_arquivo_existem_4_texturas_NO_SO_WE_EA(void){
	// int	fd;
	// char **content_map;
	// int	i;

	// fd = open(path_map, O_RDONLY);
	// i = 0;
	// while (get_next_line(fd, &content_map[i++]))
	// 	;
	// content_map[i] = NULL;
	// close(fd);
	// TEST_ASSERT_EQUAL_INT (TRUE, valid_texture(content_map));
//}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testando_is_invalid_arg_sem_parametro);
	RUN_TEST(testando_com_um_arquivo_sem_ponto_cub);
	RUN_TEST(testando_se_o_arquivo_existe);
	RUN_TEST(testando_se_o_arquivo_esta_vazio);
	RUN_TEST(testando_se_o_arquivo_nao_esta_vazio);
	RUN_TEST(testando_se_as_texturas_nao_sao_validas);
	RUN_TEST(testando_se_as_texturas_sao_validas);
	RUN_TEST(testando_se_os_arquivos_da_textura_existe_e_sao_validos);
	RUN_TEST(testando_se_os_arquivos_da_textura_nao_existe);
	RUN_TEST(testando_se_a_borda_do_map_tem_apenas_1);
	// RUN_TEST(testando_se_a_borda_do_map_esta_invalida);
	RUN_TEST(testando_se_o_mapa_tem_apenas_os_caracteres_permitidos);
	// RUN_TEST(testando_se_o_mapa_tem_caracteres_invalidos);
	//RUN_TEST(testando_se_dentro_do_arquivo_existem_4_texturas_NO_SO_WE_EA)
    return UNITY_END();
}
