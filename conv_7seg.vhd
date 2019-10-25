library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity conv_7seg is
Port (  
	Qsin : in STD_LOGIC_VECTOR (2 downto 0);
	sete_Seg : out STD_LOGIC_VECTOR (6 downto 0));
end conv_7seg;
 
architecture convArch of conv_7seg is
 
begin
 
process(Qsin)
begin
 
case Qsin is
when "000" =>
sete_Seg <= "0000001"; ---0
when "001" =>
sete_Seg <= "1001111"; ---1
when "010" =>
sete_Seg <= "0010010"; ---2
when "011" =>
sete_Seg <= "0000110"; ---3
when "100" =>
sete_Seg <= "1001100"; ---4
when "101" =>
sete_Seg <= "0100100"; ---5
when "110" =>
sete_Seg <= "0100000"; ---6
when "111" =>
sete_Seg <= "0001111"; ---7
when others =>
sete_Seg <= "1111111"; ---null
end case;
 
end process;
 
end convArch;