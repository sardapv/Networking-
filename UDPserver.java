import java.io.*;
import java.net.*;

class UDPserver
{
	public static void main(String args[])
	{
		try
		{
			DatagramSocket Serversock = new DatagramSocket(8000);
			BufferedReader in1=new BufferedReader(new InputStreamReader(System.in));

			String st1;
			while(true)
			{
				byte[] send_data1=new byte[1024];
				byte[] recv_data1=new byte[1024];
				DatagramPacket recv_pack1=new DatagramPacket(recv_data1,recv_data1.length);
				Serversock.receive(recv_pack1);
				String str1=null;

				str1=new String(recv_pack1.getData());
				System.out.println();
				System.out.print("received: ");
				System.out.println(str1.trim());

				System.out.printf("\nme: ");
				st1=in1.readLine();
				if(st1.equals("end"))
				{
					Serversock.close();
				}
				send_data1=st1.getBytes();
				InetAddress ad1=recv_pack1.getAddress();
				int p1=recv_pack1.getPort();
				DatagramPacket send_pack1=new DatagramPacket(send_data1,send_data1.length,ad1,p1);
				Serversock.send(send_pack1);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
