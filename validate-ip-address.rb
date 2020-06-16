# frozen_string_literal: true

# Runtime: 24 ms
# Memory Usage: 9.6 MB
def valid_ip_address(ip)
  v4 = ip.split('.')
  v6 = ip.split(':')

  if v4.size == 4 && ip.count('.') == 3
    if v4.all? { |d| d.to_i.to_s == d && d.to_i <= 255 && d.to_i >= 0 }
      'IPv4'
    else
      'Neither'
    end
  elsif v6.size == 8 && ip.count(':') == 7
    return 'Neither' unless v6.all? { |d| d.size <= 4 && !d.empty? }

    v6 = v6.map { |d| d.sub(/^[0]+/, '') }.map { |d| d == '' ? '0' : d }
    if v6.all? { |d| d.size <= 4 && d.to_i(16) >= 0 && d.upcase == d.to_i(16).to_s(16).upcase }
      'IPv6'
    else
      'Neither'
    end
  else
    'Neither'
  end
end
