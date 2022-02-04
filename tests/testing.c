/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:02:52 by coder             #+#    #+#             */
/*   Updated: 2022/02/04 21:33:19 by mavinici         ###   ########.fr       */
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
	TEST_ASSERT_EQUAL_INT (TRUE, is_invalid_arg(1, NULL));
}

void testando_com_um_arquivo_sem_ponto_cub(void){
	char *lek[2];
	lek[0] = "./cube";
	lek[1] = "./test.cuba";
	TEST_ASSERT_EQUAL_INT (TRUE, is_invalid_arg(2, lek));
}

void testando_se_o_arquivo_existe(void)
{
	char *lek[2];
	lek[0] = "./cube";
	lek[1] = "./test.cub";
	TEST_ASSERT_EQUAL_INT (TRUE, is_invalid_arg(2, lek));
}

void testando_se_o_arquivo_esta_vazio(void)
{
	TEST_ASSERT_NULL (store_content_map("./maps/empty_map.cub"));
}

void testando_se_o_arquivo_nao_esta_vazio(void)
{
	TEST_ASSERT_NOT_NULL (store_content_map("./maps/valid_map.cub"));
}

void testando_se_as_texturas_sao_validas(void)
{
	char **map_content = store_content_map("./maps/valid_map.cub");
	TEST_ASSERT_EQUAL_INT(FALSE, valid_texture(map_content));
}

// void testando_se_as_texturas_nao_sao_validas(void)
// {
// 	char **map_content = store_content_map("./maps/invalid_map.cub");
// 	TEST_ASSERT_EQUAL_INT(TRUE, valid_texture(map_content));
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
	// RUN_TEST(testando_se_as_texturas_nao_sao_validas);
	RUN_TEST(testando_se_as_texturas_sao_validas);
	//RUN_TEST(testando_se_dentro_do_arquivo_existem_4_texturas_NO_SO_WE_EA)
    return UNITY_END();
}
