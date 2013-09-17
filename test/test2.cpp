// test2.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

//�֐��錾
bool RomanToArabia( int value, char* result);
bool RomanToArabiaWork( int value, const char ones, const char fives, const char tens, char* result );

/**
 * �G���g���[�|�C���g
 */
int _tmain(int argc, _TCHAR* argv[])
{
	char buf[256] = "";
	int i=0;

	for( i=1; i<4000; i++){
		strcpy( buf, "" );
		if(RomanToArabia( i, buf ))printf( "%s \n", buf );
	}

	return 0;
}

/**
 *�@�A���r�A���������[�}�����ɕϊ�����֐�
 */
bool RomanToArabia( int value, char* result){

	char buf[256] = "", buf2[256] = "";
	int i=0,digit=0;
	//�I�[�o�[�t���[���Ȃ��悤�ɍŌ�Ƀ_�~�[������
	const char ones[] = { 'I', 'X', 'C', 'M', 'E' };
	const char fives[] = { 'V', 'L', 'D', 'E' };
		
	strcpy( buf, ""  );

	//�����𒲂ׂ�
	for( i = 10 ; value >= i ; i *= 10 ) digit++;
	
	//�P�����ϊ�����
	for( i=0; i<=digit; i++ )
	{
		if(RomanToArabiaWork( value%10, ones[i], fives[i], ones[i+1], buf2 )){
			//�����當����A�������邽�߂̏���
			strcat( buf2, buf );
			strcpy( buf, buf2 );
		}
		value /= 10;
	}

	if( strcmp( buf, "" ) != 0 ){
		strcpy( result, buf );
		return true;
	}
	
	return false;
}

/**
 * �P�`�X�̐������󂯎���������ŕϊ������Ɗ֐�
 */
bool RomanToArabiaWork( int value, const char ones, const char fives, const char tens, char* result ){
	
	char buf[8] = "";
	int i=0;

	if( value < 4 ){
		for( i=value; i>0; i-- ){
			strncat( buf, &ones, 1 );
		}
	}else if( value == 4 ){
		strncat( buf, &ones, 1 );
		strncat( buf, &fives, 1 );
	}else if( value < 9){
		strncat( buf, &fives, 1 );
		for( i=value-5; i>0; i-- ){
			strncat( buf, &ones, 1 );
		}
	}else{
		strncat( buf, &ones, 1 );
		strncat( buf, &tens, 1 );
	}
	
	if( strcmp( buf, "" ) != 0 ){
		strcpy( result, buf );
		return true;
	}

	return false;
}



